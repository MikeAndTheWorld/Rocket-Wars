#include "Components\Sub-Components\FpsCamera.h"
#include "Window.h"
#include <cstdio>

FpsCamera::FpsCamera(Object *pComponent)
{
	m_ObjectComponent = pComponent;
	m_CompName = "FPS";
}
void FpsCamera::Create()
{
	/*shift = false;*/
	PX = 0.0f;
	PY = 0.0f;
	PZ = 0.0f;
	VX = 0.0f;
	VY = 0.0f;
	VZ = 0.0f;
	//position
	FpsCameraPos.y = PY;
	FpsCameraPos.z = PZ;
	FpsCameraPos.x = PX;
	//view
	FpsCameraView.x = VX;
	FpsCameraView.y = VY;
	FpsCameraView.z = VZ;

	// Initial Field of View
	initialFoV = 45.0f;

	// angle
	//HorizontalAngle = 3.14f;
	HorizontalAngle = 0.0f;
	VerticalAngle = 0.0f;

	//zoom in or out
	Zoom = 60.0f;
}
void FpsCamera::Delete()
{

}
void FpsCamera::Render(Shader & shader)
{
	//if (CameraMode == 1 || CameraMode == 5) // 1st person or free mode
	//{
	//	glm::mat4 view = glm::lookAt
	//	(
	//		FpsCameraPos - glm::vec3(0.0f, -10.0f, Zoom),
	//		FpsCameraPos - glm::vec3(0.0f, -10.0f, Zoom) + FpsCameraView,
	//		up
	//	);
	//	GLuint loc = glGetUniformLocation(shader.ID, "mView");
	//	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(view));
	//}
}
void FpsCamera::Update(double DeltaTime)
{
	int width, height;
	double xPos, yPos;
	
	glfwGetWindowSize(Window::getInstance()->getWindow(), &width, &height); //get window size
	glfwGetCursorPos(Window::getInstance()->getWindow(), &xPos, &yPos); // get mouse position

	// mouse position
	MousePos.x = xPos;
	MousePos.y = yPos;
	
	//speed
	FpsCameraSpeed = 15.0f; // 3 units / second

	MouseSpeed = 0.75f; // mouse movement speed

	//the angle
	HorizontalAngle += MouseSpeed * 1 / REFRESH_RATE * (width / 2 - xPos);
	VerticalAngle += MouseSpeed * 1 / REFRESH_RATE * (height / 2 - yPos);

	////lock max top and bottom rotation
	if (VerticalAngle < -89.9f)
	{
		VerticalAngle = -89.9f;
	}
	if (VerticalAngle > 89.9f)
	{
		VerticalAngle = 89.9f;
	}
	if (CameraMode != 5) //lock apart from free mode
	{
		if (HorizontalAngle < -55.0f)
		{
			HorizontalAngle = -55.0f;
		}
		if (HorizontalAngle > 55.0f)
		{
			HorizontalAngle = 55.0f;
		}
	}

	// angle of the view
	FpsCameraView.x = cos(glm::radians(VerticalAngle)) * sin(glm::radians(HorizontalAngle));
	FpsCameraView.y = sin(glm::radians(VerticalAngle));
	FpsCameraView.z = cos(glm::radians(VerticalAngle)) * cos(glm::radians(HorizontalAngle));

	right = glm::normalize(glm::vec3(sin(glm::radians(HorizontalAngle) - 3.14 / 2.0f), 0, cos(glm::radians(HorizontalAngle) - 3.14 / 2.0f)));
	up = glm::normalize(glm::cross(right, FpsCameraView));

	m_ObjectComponent->getComponent<Transform>()->SetDirect(glm::normalize(glm::vec3(FpsCameraView.x, FpsCameraView.y, FpsCameraView.z)));
	//m_ObjectComponent->getComponent<Transform>()->SetAD(glm::normalize(glm::vec3(sin(HorizontalAngle - 3.14f / 2.0f), 0.0f, cos(HorizontalAngle - 3.14f / 2.0f))));
	//cout << HorizontalAngle << endl;
	
	if (CameraMode == 5) // free mode
	{
		//forward
		if (glfwGetKey(Window::getInstance()->getWindow(), GLFW_KEY_UP) == GLFW_PRESS)
		{
			//printf("%f\n", FpsCameraSpeed);
			FpsCameraPos.x += FpsCameraView.x * 1 / REFRESH_RATE * FpsCameraSpeed;
			FpsCameraPos.y += FpsCameraView.y * 1 / REFRESH_RATE * FpsCameraSpeed;
			FpsCameraPos.z += FpsCameraView.z * 1 / REFRESH_RATE * FpsCameraSpeed;

			//m_ObjectComponent->getComponent<Transform>()->SetPos(glm::vec3(FpsCameraPos.x, FpsCameraPos.y, FpsCameraPos.z));

		}
		//back
		if (glfwGetKey(Window::getInstance()->getWindow(), GLFW_KEY_DOWN) == GLFW_PRESS)
		{
			FpsCameraPos.x -= FpsCameraView.x * 1 / REFRESH_RATE * FpsCameraSpeed;
			FpsCameraPos.y -= FpsCameraView.y * 1 / REFRESH_RATE * FpsCameraSpeed;
			FpsCameraPos.z -= FpsCameraView.z * 1 / REFRESH_RATE * FpsCameraSpeed;
			//m_ObjectComponent->getComponent<Transform>()->SetPos(glm::vec3(FpsCameraPos.x, FpsCameraPos.y, FpsCameraPos.z));
		}
		//left
		if (glfwGetKey(Window::getInstance()->getWindow(), GLFW_KEY_LEFT) == GLFW_PRESS)
		{
			FpsCameraPos.x -= sin(glm::radians(HorizontalAngle) - 3.14f / 2.0f)* 1 / REFRESH_RATE * FpsCameraSpeed;
			FpsCameraPos.z -= cos(glm::radians(HorizontalAngle) - 3.14f / 2.0f)* 1 / REFRESH_RATE * FpsCameraSpeed;
			//m_ObjectComponent->getComponent<Transform>()->SetPos(glm::vec3(FpsCameraPos.x, 0.0f , FpsCameraPos.z));

		}
		//right
		if (glfwGetKey(Window::getInstance()->getWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS)
		{
			FpsCameraPos.x += sin(glm::radians(HorizontalAngle) - 3.14f / 2.0f)* 1 / REFRESH_RATE * FpsCameraSpeed;
			FpsCameraPos.z += cos(glm::radians(HorizontalAngle) - 3.14f / 2.0f)* 1 / REFRESH_RATE * FpsCameraSpeed;

			//m_ObjectComponent->getComponent<Transform>()->SetPos(glm::vec3(FpsCameraPos.x, 0.0f , FpsCameraPos.z));

		}
	}
	else
	{
		FpsCameraPos = m_ObjectComponent->getComponent<Transform>()->GetPos(); // get pos
		FpsCameraView = m_ObjectComponent->getComponent<Transform>()->GetDirect(); // get direct
	}

	//zoom
	if (glfwGetKey(Window::getInstance()->getWindow(), GLFW_KEY_PAGE_UP) == GLFW_PRESS)
	{
		Zoom = Zoom + 2.0f;
			
	}
	if (glfwGetKey(Window::getInstance()->getWindow(), GLFW_KEY_PAGE_DOWN) == GLFW_PRESS)
	{
		Zoom = Zoom - 2.0f;
	}
	if (Zoom >= 200.0f)
	{
		Zoom = 200.0f;
	}
	if (Zoom <= 40.0f)
	{
		Zoom = 40.0f;
	}

	if (glfwGetKey(Window::getInstance()->getWindow(), GLFW_KEY_1) == GLFW_PRESS) // 1
	{
		CameraMode = 1;
	}
	if (glfwGetKey(Window::getInstance()->getWindow(), GLFW_KEY_5) == GLFW_PRESS) // 5
	{
		CameraMode = 5;
	}

	if (CameraMode == 1 || CameraMode == 5) // 1st person or free mode
	{
		view = glm::lookAt
		(
			FpsCameraPos - glm::vec3(0.0f, -10.0f, Zoom),
			FpsCameraPos - glm::vec3(0.0f, -10.0f, Zoom) + FpsCameraView,
			up
		);

	}

}

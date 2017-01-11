#include "Components\Sub-Components\FpsCamera.h"
#include "Window.h"
#include <cstdio>

FpsCamera::FpsCamera(GLFWwindow* window)
{
	this->window = window;
	shift = false;

	PX = 0.0f; 
	PY = 0.f; 
	PZ = -20.0f;
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
	HorizontalAngle = 3.14f;
	VerticalAngle = 0.0f;

}
void FpsCamera::Update(Shader * shader)
{
	int width, height;
	double xPos, yPos;
	
	glfwGetWindowSize(window, &width, &height); //get window size
	glfwGetCursorPos(window, &xPos, &yPos); // get mouse position

	// mouse position
	MousePos.x = xPos;
	MousePos.y = yPos;
	
	//speed
	//CameraSpeed = 0.05f; // 3 units / second
	if (shift){
		FpsCameraSpeed = 0.1f; // holding shift to move faster
	}
	else { FpsCameraSpeed = 5.f; }
	MouseSpeed = 0.5f; // mouse movement speed


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

	// angle of the view
	FpsCameraView.x = cos(glm::radians(VerticalAngle)) * sin(glm::radians(HorizontalAngle));
	FpsCameraView.y = sin(glm::radians(VerticalAngle));
	FpsCameraView.z = cos(glm::radians(VerticalAngle)) * cos(glm::radians(HorizontalAngle));

	//forward
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
	printf("%f\n", FpsCameraSpeed);
		FpsCameraPos.x += FpsCameraView.x * 1 / REFRESH_RATE * FpsCameraSpeed;
		FpsCameraPos.y += FpsCameraView.y * 1 / REFRESH_RATE * FpsCameraSpeed;
		FpsCameraPos.z += FpsCameraView.z * 1 / REFRESH_RATE * FpsCameraSpeed;
	}
	//back
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		FpsCameraPos.x -= FpsCameraView.x * 1 / REFRESH_RATE * FpsCameraSpeed;
		FpsCameraPos.y -= FpsCameraView.y * 1 / REFRESH_RATE * FpsCameraSpeed;
		FpsCameraPos.z -= FpsCameraView.z * 1 / REFRESH_RATE * FpsCameraSpeed;
	}
	//left
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		FpsCameraPos.x -= sin(glm::radians(HorizontalAngle) - 3.14f / 2.0f)* 1 / REFRESH_RATE * FpsCameraSpeed;
		FpsCameraPos.z -= cos(glm::radians(HorizontalAngle) - 3.14f / 2.0f)* 1 / REFRESH_RATE * FpsCameraSpeed;

	}
	//right
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		FpsCameraPos.x += sin(glm::radians(HorizontalAngle) - 3.14f / 2.0f)* 1 / REFRESH_RATE * FpsCameraSpeed;
		FpsCameraPos.z += cos(glm::radians(HorizontalAngle) - 3.14f / 2.0f)* 1 / REFRESH_RATE * FpsCameraSpeed;
	}

	glm::mat4 view = glm::lookAt(
		FpsCameraPos,
		FpsCameraPos + FpsCameraView,
		glm::vec3(0, 1, 0)
	);

	GLuint loc = glGetUniformLocation(shader->ID, "mView");
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(view));
}

// move
void FpsCamera::SpeedUp()
{
	shift = true;
}
void FpsCamera::SpeedDown()
{
	shift = false; // not holding shift
}
void FpsCamera::MoveForward()
{
	FpsCameraPos.x += FpsCameraView.x * REFRESH_RATE * FpsCameraSpeed;
	FpsCameraPos.y += FpsCameraView.y * REFRESH_RATE * FpsCameraSpeed;
	FpsCameraPos.z += FpsCameraView.z * REFRESH_RATE * FpsCameraSpeed;
}
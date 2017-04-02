#include "Components\Sub-Components\Aim.h"
#include "Window.h"
#include <cstdio>

Aim::Aim(Object *pComponent)
{
	m_ObjectComponent = pComponent;
	m_CompName = "Aim";
}
void Aim::Create() //starting
{
	CannonAngle.x = 0.0f;
	CannonAngle.y = 0.0f;
	CannonAngle.z = 0.0f;
	AimHorizontalAngle = 0.0f;
	AimVerticalAngle = 0.0f;
}

bool Aim::rotate = false;

void Aim::Update(double DeltaTime)//updating
{
	/*CannonAngle.x = cos(glm::radians(VerticalAngle)) * sin(glm::radians(HorizontalAngle)) * DeltaTime;
	CannonAngle.y = sin(glm::radians(VerticalAngle)) * 0;
	CannonAngle.z = cos(glm::radians(VerticalAngle)) * cos(glm::radians(HorizontalAngle)) * DeltaTime;*/

	//lock
	if (rotate == true)
	{
		if (AimVerticalAngle >= 1.57075f)
		{
			AimHorizontalAngle = 0.0f;
			AimVerticalAngle = 1.57075f;
		}
		else if (AimVerticalAngle <= -1.57075f)
		{
			AimHorizontalAngle = 0.0f;
			AimVerticalAngle = -1.57075f;
		}
		else
		{
			AimVerticalAngle = AimVerticalAngle;
			AimHorizontalAngle = 1.0f;
		}
		if (AimVerticalAngle == 0.0f)
		{
			AimHorizontalAngle = 1.0f;
		}
		CannonAngle.x = AimVerticalAngle;
		CannonAngle.y = 0.0f;// AimHorizontalAngle;
		CannonAngle.z = 0.0f;
	}
	
	//AimHorizontalAngle = std::abs(AimVerticalAngle);


	//static bool to determine both cannon and rocket are rotatable
	if (m_ObjectComponent->CheckComponentExists<Movement>()) // check if rocket
	{
		if (m_ObjectComponent->getComponent<Movement>()->GetVelocity() == glm::vec3(0.0f, 0.0f, 0.0f)) // check if the rocket is not moving
		{
			rotate = true; // if the rocket has no movement it can still rotate
		}
		else
		{
			rotate = false; // else dont rotate
		}
	}

	if (rotate == true)
	{
		if (glfwGetKey(Window::getInstance()->getWindow(), GLFW_KEY_D) == GLFW_PRESS) // right
		{
			AimVerticalAngle = AimVerticalAngle - 3.1415f * DeltaTime;
			m_ObjectComponent->getComponent<Transform>()->SetRotate(glm::vec3(CannonAngle.z, 3.1415f / 2.0f, CannonAngle.x));
		}
		if (glfwGetKey(Window::getInstance()->getWindow(), GLFW_KEY_A) == GLFW_PRESS) // left
		{
			AimVerticalAngle = AimVerticalAngle + 3.1415f * DeltaTime;
			m_ObjectComponent->getComponent<Transform>()->SetRotate(glm::vec3(CannonAngle.z, 3.1415f / 2.0f, CannonAngle.x));
		}

		/*CannonAngle = {
			sin(VerticalAngle),
			0,
			cos(VerticalAngle)
		};*/

		//m_ObjectComponent->getComponent<Transform>()->SetRotate(glm::normalize(glm::vec3(CannonAngle.x, CannonAngle.y, CannonAngle.z)));
		//m_ObjectComponent->getComponent<Transform>()->SetRotate(glm::normalize(CannonAngle));

		m_ObjectComponent->getComponent<Transform>()->SetAim(glm::vec3(sin(AimVerticalAngle),cos(AimVerticalAngle), 0.0f));

		/*cout << CannonAngle.x << " " << CannonAngle.y << " " << CannonAngle.z << " " << AimVerticalAngle << " " << AimHorizontalAngle << endl;*/
	}
}
void Aim::Render(Shader & shader)
{

}
void Aim::Delete()
{

}
#include "Components\Sub-Components\BAR.h"
#include "Window.h"
#include <cstdio>

BAR::BAR(Object *pComponent)
{
	m_ObjectComponent = pComponent;
	m_CompName = "BAR";
}
void BAR::Create() //starting
{
	Power = 1.0f;
}
void BAR::Update(double DeltaTime)//updating
{	
	//Power = Power + m_ObjectComponent->getComponent<Movement>()->GetRocketPower();
	if (glfwGetKey(Window::getInstance()->getWindow(), GLFW_KEY_W) == GLFW_PRESS) // forward
	{
		if (Power < 290.0f)
		{
			Power = Power + 1.45f;
		}
		else
		{
			Power = 290.0f;
		}
	}
	else
	{
		Power = Power - 1.45f;
		if (Power <= 1.0f)
		{
			Power = 1.0f;
		}
	}
	m_ObjectComponent->getComponent<Transform>()->SetScale(glm::vec3(m_ObjectComponent->getComponent<Transform>()->GetScale().x, Power , m_ObjectComponent->getComponent<Transform>()->GetScale().z));
}
void BAR::Render(Shader & shader)
{
	
}
void BAR::Delete()
{

}
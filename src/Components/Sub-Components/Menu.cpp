#include "Components\Sub-Components\Menu.h"
#include "Window.h"
#include <cstdio>

Menu::Menu(Object *pComponent)
{
	m_ObjectComponent = pComponent;
	m_CompName = "Menu";
}
void Menu::Create() //starting
{

}
void Menu::Update(double DeltaTime)//updating
{	
	if (glfwGetKey(Window::getInstance()->getWindow(), GLFW_KEY_ENTER) == GLFW_PRESS) // enter
	{
		m_ObjectComponent->getComponent<Transform>()->SetScale(glm::vec3(0.0f, 0.0f, 0.0f));
	}
}
void Menu::Render(Shader & shader)
{
	
}
void Menu::Delete()
{

}
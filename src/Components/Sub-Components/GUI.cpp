#include "Components\Sub-Components\GUI.h"
#include "Window.h"
#include <cstdio>

GUI::GUI(Object *pComponent)
{
	m_ObjectComponent = pComponent;
	m_CompName = "GUI";
}
void GUI::Create() //starting
{
	View = glm::ortho((1920.0f / 2.0f) * 0.0f,1920.0f,1080.0f, (1080.0f / 2.0f) * 0.0f,-2.0f,2.0f);
	Projection = glm::mat4(1.0f);//glm::lookAt(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}
void GUI::Update(double DeltaTime)//updating
{
	
}
void GUI::Render(Shader & shader)
{
	GLuint loc = glGetUniformLocation(shader.ID, "mView");
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(View));

	GLuint loc2 = glGetUniformLocation(shader.ID, "mProjection");
	glUniformMatrix4fv(loc2, 1, GL_FALSE, glm::value_ptr(Projection));
}
void GUI::Delete()
{

}
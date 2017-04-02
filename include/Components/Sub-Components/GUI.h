#ifndef GUI_H
#define GUI_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include <gtx/transform.hpp>
#include <math.h>

#include "Components\Components.h"
#include "Rendering\Shaders.h"
#include "Components\Sub-Components\Transform.h"
#include "Object.h"

class GUI : public Component
{
private:

	glm::mat4 View;
	glm::mat4 Projection;

public:
	GUI(Object *pComponent); // move

	void Create(); //starting
	void Delete();
	void Update(double DeltaTime); //updating
	void Render(Shader & shader);


};
#endif

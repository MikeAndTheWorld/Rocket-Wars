#ifndef BAR_H
#define BAR_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include <gtx/transform.hpp>
#include <math.h>
#include "Components\Components.h"
#include "Components\Sub-Components\Transform.h"
#include "Components\Sub-Components\Movement.h"
#include "Object.h"

class BAR : public Component
{
private:
	Transform * transform;
	GLFWwindow * window;

	float Power;

public:
	BAR(Object *pComponent); // move

	void Create(); //starting
	void Delete();
	void Update(double DeltaTime); //updating
	void Render(Shader & shader);
};
#endif
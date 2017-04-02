#ifndef AIM_H
#define AIM_H

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

class Aim : public Component
{
private:
	Transform * transform;
	GLFWwindow * window;

	glm::vec3 CannonAngle;
	float AimHorizontalAngle;
	float AimVerticalAngle;
	static bool rotate;

public:
	Aim(Object *pComponent); // move

	void Create(); //starting
	void Delete();
	void Update(double DeltaTime); //updating
	void Render(Shader & shader);


};
#endif
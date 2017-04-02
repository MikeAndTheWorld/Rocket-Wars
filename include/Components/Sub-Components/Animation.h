#ifndef ANIMATION_H
#define ANIMATION_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include <gtx/transform.hpp>

#include "Components\Components.h"
#include "Rendering\Shaders.h"
#include "Components\Sub-Components\Transform.h"
#include "Object.h"

class Animation : public Component
{
private:
	Transform * transform;
	GLFWwindow * window;

	glm::vec3 AnimationAngle; // speed x y z
	float AnimationVerticalAngle; // rotate speed
	float AnimationHorizontalAngle;
public:
	Animation(Object *pComponent);
	void Create(); //starting
	void Delete();
	void Update(double DeltaTime); //updating
	void Render(Shader & shader);


};
#endif
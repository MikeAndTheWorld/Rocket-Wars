#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include <gtx/transform.hpp>

#include "Rendering\Shaders.h"

class Movement
{
private:
	GLFWwindow * window;

public:
	Movement() {}
	Movement(GLFWwindow* window);
};
#endif

#ifndef TPSCAMERA_H
#define TPSCAMERA_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include <gtx/transform.hpp>

#include "Rendering\Shaders.h"

class TpsCamera
{
private:

public:
	TpsCamera() {}
	TpsCamera(GLFWwindow* window);

};
#endif

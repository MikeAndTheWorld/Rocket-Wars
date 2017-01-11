#ifndef FPS_CAMERA_H
#define FPS_CAMERA_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include <gtx/transform.hpp>

#include "Rendering\Shaders.h"

class FpsCamera
{
private:

	const int REFRESH_RATE = 60;
	// horizontal angle
	float HorizontalAngle;
	// vertical angle
	float VerticalAngle;
	// Initial Field of View
	float initialFoV;
	bool shift;
	float FpsCameraSpeed; // 3 units / second
	float MouseSpeed; // mouse movement speed

	// camera position and direction
	//camera
	float PX ; // pos x
	float PY ; // pos y
	float PZ ; // pos z
	float VX ; // view x
	float VY ; // view y
	float VZ ; // view z

	//mouse position
	glm::vec2 MousePos;
	// camera pos and view
	glm::vec3 FpsCameraPos;
	glm::vec3 FpsCameraView;
	GLFWwindow * window;

public:
	FpsCamera() {}
	FpsCamera(GLFWwindow* window);
	void Update(Shader * shader);
	void MoveForward();
	void SpeedUp();
	void SpeedDown();
};
#endif
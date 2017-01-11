#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtx/transform.hpp>
#include "Components\Sub-Components\FpsCamera.h"

class Window
{
private:
	
	static Window* instance;
	static bool isInstanced;

	// fps lock
	const int REFRESH_RATE = 60;

	int WindowWidth;
	int WindowHeight;
	void setSize(int setwidth, int setheight);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

	GLFWwindow *glfwWindow;


public:
	static Window* getInstance();

	Window(int width,int height);
	static FpsCamera getFpsCamera();
	void getSize(int &getwidth, int &getheight);

	GLFWwindow * getWindow() {
		return glfwWindow;
	}

	FpsCamera m_FpsCamera;
};
#endif

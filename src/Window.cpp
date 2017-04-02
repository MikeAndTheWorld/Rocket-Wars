#include "Window.h"
#include <string>

//setting singleton init values
bool Window::isInstanced = false;
Window* Window::instance = NULL;


void mouse_callback(GLFWwindow* window, double xpos, double ypos) 
{

}

void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) 
{

}

Window* Window::getInstance() 
{
	return instance; // return instance
}

void Window::getSize(int &width, int &height)
{
	width = WindowWidth;
	height = WindowHeight;
}

Window::Window(int width, int height)
{
	using std::string;

	isInstanced = true;
	instance = this;

	WindowWidth = width;
	WindowHeight = height;

	// Initialize GLFW
	if (!glfwInit()) exit(EXIT_FAILURE);
	

	// Select OpenGL 4.3 with a forward compatible core profile.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

	// Open the window
	string title = "Rocket Wars";
	glfwWindow = glfwCreateWindow(width,height, title.c_str(), NULL, NULL);
	if (!glfwWindow) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(glfwWindow);

	glfwSetCursorPosCallback(glfwWindow, mouse_callback);
	glfwSetInputMode(glfwWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetKeyCallback(glfwWindow, key_callback);
}
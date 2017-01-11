#include "Game.h"


#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include <string>
#include <glm.hpp>
#include <gtx/transform.hpp>


void Game::GameLoop(Window *window,Scene & scene) 
{
	const float TickPS = 1.0f / 60.0f;
	double DeltaTick = glfwGetTime();
	double OldTick = 0.0;
	double NewTick = 0.0;

	while (!glfwWindowShouldClose(window->getWindow()) && !glfwGetKey(window->getWindow(), GLFW_KEY_ESCAPE)) {
	
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		scene.Update(0);
		scene.Render();

		glfwSwapBuffers(window->getWindow());
		glfwPollEvents();
		//window->camera.CameraUpdate(window->getWindow());
	
	}

}

 ///////// Main loop  /////////////////////////////////////
 //void mainLoop(Window *window,Scene & scene) {
	//while (!glfwWindowShouldClose(window->getWindow()) && !glfwGetKey(window->getWindow(), GLFW_KEY_ESCAPE)) {
	//	 //GLUtils::checkForOpenGLError(__FILE__,__LINE__);

	//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//	scene.update(0);
	//	scene.render();

	//	glfwSwapBuffers(window->getWindow());
	//	glfwPollEvents();
	//	//window->camera.CameraUpdate(window->getWindow());
	// }
 //}

int main() {

	Window * window = new Window(1920, 1080);

	glewExperimental = GL_TRUE;
	glewInit();
	glEnable(GL_DEPTH_TEST);

	Scene scene;

	Game game;

	FpsCamera * m_FpsCamera = new FpsCamera(window->getWindow());

	scene.initScene(m_FpsCamera);

	// Enter the main loop
	game.GameLoop(window, scene);

	// Close window and terminate GLFW
	glfwTerminate();

	// Exit program
	exit(EXIT_SUCCESS);

}

#include "Game.h"

#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include <string>
#include <glm.hpp>
#include <gtx/transform.hpp>
#include <time.h>

void Game::GameLoop(Window *window,Scene & scene) 
{
	//time
	const float TickPS = 1.0f / 60.0f;
	double NewTimer = glfwGetTime();
	double DeltaTime = NewTimer - OldTimer;
	while (DeltaTime < TickPS)
	{
		NewTimer = glfwGetTime();
		DeltaTime = NewTimer - OldTimer; //time step (h)
	}
	OldTimer = NewTimer;
	//std::cout << DeltaTime << " " << TickPS << " " << std::endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear
	scene.Update(DeltaTime); // update
	scene.Render(); //render

	glfwSwapBuffers(window->getWindow()); //window
	glfwPollEvents();
	//window->camera.CameraUpdate(window->getWindow());

}

 ///////// Main loop  /////////////////////////////////////
int main() {

	Window * window = new Window(1920, 1080 - 20);// size

	glewExperimental = GL_TRUE;
	glewInit();
	glEnable(GL_DEPTH_TEST);
	
	Scene scene; // scene

	Game game; // game

	srand(time(NULL));


	//FpsCamera * m_FpsCamera = new FpsCamera(window->getWindow());

	scene.initScene();

	// Enter the main loop
	while (!glfwWindowShouldClose(window->getWindow()) && !glfwGetKey(window->getWindow(), GLFW_KEY_ESCAPE)) 
	{

		game.GameLoop(window, scene);

	}

	// Close window and terminate GLFW
	glfwTerminate();

	// Exit program
	exit(EXIT_SUCCESS);

}

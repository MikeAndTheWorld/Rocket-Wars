#ifndef GAME_H
#define GAME_H

#include <GL\glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "window.h"
#include "Scene.h"
//#include "Rendering\ResourceList.h"
#include "Components\Sub-Components\Transform.h"
#include "Components\Sub-Components\Render.h"
#include "Components\Sub-Components\MovementControl.h"
#include "Components\Sub-Components\FpsCamera.h"

using namespace std;

class Game
{
private:


public:
	void GameUpdate();
	void GameLoop(Window *window, Scene & scene);
	Game() {

	}
};
#endif

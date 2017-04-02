#ifndef SCENE_H_
#define SCENE_H_

#include <GL\glew.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>

#include <vector>
#include <map>
#include <stdlib.h>

#include "Components\Sub-Components\FpsCamera.h"
#include "Collision.h"
#include "Object.h"
#include "Rendering\Texture.h"

#include "Window.h"

class Scene
{
private:
	std::vector<Object*> objectList; // object list
	std::vector<Object*> GUIList; // object list
	std::map<std::string, Shader> ShaderList;
	std::map<std::string, Texture> TextureList;

	Collision collision;

	//FpsCamera * m_FpsCamera;
	int width, height;
	int End = 0;

public:

	void initScene();

	void setLightParams(/*FpsCamera * m_FpsCamera*/);

	void Update(double DeltaTime);
	void Render();
};
#endif
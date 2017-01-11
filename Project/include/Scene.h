#ifndef SCENE_H_
#define SCENE_H_

#include <GL\glew.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>

#include <vector>
#include <map>
#include <stdlib.h>

#include "Components\Sub-Components\FpsCamera.h"

#include "Object.h"

#include "Window.h"

class Scene
{
private:
	std::vector<Object*> modelList;
	std::map<std::string, Shader> ShaderList;
	std::map<std::string, Texture> TextureList;

	FpsCamera * m_FpsCamera;
	int width, height;

public:

	void initScene(FpsCamera * m_FpsCamera);

	void setLightParams(FpsCamera * m_FpsCamera);

	void Update(double DeltaTime);
	void Render();
};
#endif
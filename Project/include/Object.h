#ifndef OBJECT_H_
#define OBJECT_H_

#include "Model.h"



#include <GL\glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "ModelLoader.h"
#include "Rendering\Texture.h"
#include "Rendering\Shaders.h"

class Component;
class Model;

class Object
{
private:
	std::vector<Component*> ComponentList;
	
public:
	Object() {}
	Object(char * FilePath, Texture texture);
	void Create(char * FilePath, Texture texture);
	void Update(double DeltaTime);
	void Render(Shader &shader);
	std::vector<Component*> GetComponentList();
};
#endif

#include "Object.h"

Object::Object(char * FilePath, Texture texture)
{
	Create(FilePath, texture);
}
void Object::Create(char * FilePath, Texture texture)
{
	Model * temp = nullptr;
	ModelLoader loader;
	temp = loader.Load(FilePath);
	
	temp->Create();
	temp->texture = texture;
	ComponentList.push_back(temp);

	for (auto comp : ComponentList)
	{
		comp->Create();
	}
}
void Object::Update(double DeltaTime)
{
	for (auto comp : ComponentList)
	{
		comp->Update(DeltaTime);
	}
}
void Object::Render(Shader &shader)
{
	for (auto comp : ComponentList)
	{
		comp->Render(shader);
	}
}
std::vector<Component*> Object::GetComponentList()
{
	return ComponentList;
}



#ifndef OBJECT_H_
#define OBJECT_H_


#include <GL\glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "Rendering\Shaders.h"
#include "Components\Components.h"
//
//#include "Rendering\Texture.h"
//
//#include "Components\Sub-Components\Transform.h"
//#include "Components\Sub-Components\Movement.h"
//#include "Components\Sub-Components\FpsCamera.h"
//#include "Components\Sub-Components\Animation.h"
//#include "Components\Sub-Components\Aim.h"
//#include "Components\Sub-Components\ConvexHull.h"
//#include "Components\Sub-Components\CollideMovement.h"
//#include "Components\Sub-Components\Collided.h"
//#include "Components\Sub-Components\UniqueBehaviors.h"
//
//#include "Model.h"


//class Component;
//class Model;
//class Movement;
//class Aim;
//class Transform;
//class Animation;
//class ConvexHull;
//class CollideMovement;
//class Collided;
//
//class Texture;
//class Shader;
//class BoxCollisionActivity;
//class ShipCollisionActivity;

class Component;

class Object
{
private:
	std::vector<Component*> ComponentList;

public:
	Object();
	void Create(/*char * FilePath*/);
	void Update(double DeltaTime);
	void Render(Shader &shader);
	void AddComponentList(Component  * cList);

	template<typename CT> //component type reads in
	CT * getComponent() 
	{
		for (auto C : ComponentList)
		{
			if (C != nullptr)
			{
				if (CT * foundComp = dynamic_cast<CT*>(C))
				{
					return foundComp;
				}
			}
		}
		return nullptr;
	}
	std::vector<Component*> GetComponentList(); // vector of component

	template<typename T>
	bool CheckComponentExists()
	{
		if (ComponentList.size() > 0)
			for (std::vector<Component*>::iterator i = ComponentList.begin(); i != ComponentList.end(); ++i)
			{
				if (*i != nullptr)
				{
					if (T* type = dynamic_cast<T*>(*i))
					{
						return true;
					}
				}
			}
		return false;
	}
};
#endif

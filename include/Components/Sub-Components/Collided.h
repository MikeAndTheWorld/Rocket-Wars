#ifndef COLLIDED_H
#define COLLIDED_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include <gtx/transform.hpp>
#include <math.h>

//#include "Components\Components.h"
//#include "Rendering\Shaders.h"
//#include "Components\Sub-Components\Transform.h"
//#include "Components\Sub-Components\ConvexHull.h"
#include "Object.h"
class Object;

class Collided : public Component
{
private:

public:
	Collided() {}
	Collided(Object *pComponent); // move
	virtual void Delete() = 0; //destorying
	virtual void Create() = 0; //starting
	virtual void Update(double DeltaTime) = 0; //updating
	virtual void Render(Shader & shader) = 0;

	virtual void PostCollision(Object * collidedObject) = 0;

};
#endif

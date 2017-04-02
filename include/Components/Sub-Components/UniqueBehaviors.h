#ifndef UNIQUE_BEHAVOIRS_H
#define UNIQUE_BEHAVOIRS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include <gtx/transform.hpp>
#include <gtx\vector_angle.hpp>
#include <math.h>

//#include "Components\Components.h"
//#include "Rendering\Shaders.h"
//#include "Components\Sub-Components\Transform.h"
#include "Components\Sub-Components\Movement.h"
#include "Components\Sub-Components\Collided.h"
#include "Components\Sub-Components\CollideMovement.h"
#include "Object.h"

class ConvexHull;
class Object;

class BoxCollisionActivity : public Collided
{
private:

public:

	bool Gen;
	int Zz;
	//Transform * transform;
	//Object * object;
	//Movement * movement;
	//CollideMovement * collideMovement;

	BoxCollisionActivity(Object *pComponent); // move
	void Create(); //starting
	void Delete();
	void Update(double DeltaTime); //updating
	void Render(Shader & shader);

	virtual void PostCollision(Object * collidedObject);
};


class ShipCollisionActivity : public Collided {
private:

public:
	
	bool Gen;
	int Zz;

	//Transform * transform;
	//Object * object;
	//Movement * movement;
	//CollideMovement * collideMovement;

	ShipCollisionActivity(Object *pComponent); // move
	void Create(); //starting
	void Delete();
	void Update(double DeltaTime); //updating
	void Render(Shader & shader);

	virtual void PostCollision(Object * collidedObject);

};

class BlackHoleCollisionActivity : public Collided {
private:

public:

	//Transform * transform;
	//Object * object;
	//Movement * movement;
	//CollideMovement * collideMovement;

	BlackHoleCollisionActivity(Object *pComponent); // move
	void Create(); //starting
	void Delete();
	void Update(double DeltaTime); //updating
	void Render(Shader & shader);

	virtual void PostCollision(Object * collidedObject);

};

class WormHoleCollisionActivity : public Collided {
private:

public:

	//Transform * transform;
	//Object * object;
	//Movement * movement;
	//CollideMovement * collideMovement;

	WormHoleCollisionActivity(Object *pComponent); // move
	void Create(); //starting
	void Delete();
	void Update(double DeltaTime); //updating
	void Render(Shader & shader);

	virtual void PostCollision(Object * collidedObject);

};

class EmptyCollisionActivity : public Collided {
private:

public:

	Object * object;

	EmptyCollisionActivity(Object *pComponent); // move
	void Create(); //starting
	void Delete();
	void Update(double DeltaTime); //updating
	void Render(Shader & shader);

	virtual void PostCollision(Object * collidedObject);

};
#endif

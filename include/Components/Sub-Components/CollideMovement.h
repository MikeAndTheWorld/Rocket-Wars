#ifndef COLLIDE_MOVEMENT_H
#define COLLIDE_MOVEMENT_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include <gtx/transform.hpp>
#include <math.h>

#include "Components\Components.h"
//#include "Rendering\Shaders.h"
#include "Components\Sub-Components\Transform.h"


class CollideMovement : public Component
{
private:
	Transform * transform;
	GLFWwindow * window;

	glm::vec3 MovementPos; // x y z
	float MovementSpeed; // speed

	float MovementX; // pos x
	float MovementY; // pos y
	float MovementZ; // pos z

	glm::vec3 Move;

	//rk4
	glm::vec3 k1;
	glm::vec3 k2;
	glm::vec3 k3;
	glm::vec3 k4;

	glm::vec3 Force;
	glm::vec3 DragForce;
	glm::vec3 Acceleration;

	glm::vec3 Velocity;
	glm::vec3 Displacement;

	glm::vec3 Aim;
	float ShipSpeed;

	

public:
	CollideMovement(Object *pComponent); // move

	void SetVelocity(glm::vec3 pVelocity) // set speed
	{
		Velocity = pVelocity; // velocity from shape 1 gets turn into acc for shape 2
	}
	void SetAim(glm::vec3 pAim) // set speed
	{
		Aim = pAim; // velocity from shape 1 gets turn into acc for shape 2
	}
	glm::vec3 GetVelocity()
	{
		return Velocity;
	}
	glm::vec3 GetAim()
	{
		return Aim;
	}
	void Create(); //starting
	void Delete();
	void Update(double DeltaTime); //updating
	void Render(Shader & shader);


};
#endif

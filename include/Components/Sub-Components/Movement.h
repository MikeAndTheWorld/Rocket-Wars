#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include <gtx/transform.hpp>
#include <math.h>
//
#include "Components\Components.h"
//#include "Rendering\Shaders.h"
#include "Components\Sub-Components\Transform.h"


class Movement : public Component
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
	glm::vec3 GravityForce;
	glm::vec3 Acceleration;

	glm::vec3 Velocity = glm::vec3(0.0f,0.0f,0.0f);
	glm::vec3 Displacement;

	glm::vec3 Aim;
	float RocketPower = 0.0f;

	int MovementCounter;

	float Mass;
	bool HasRocketFired;
	bool down;
	glm::vec3 GravitationalPull;
	glm::vec3 GravityDistance;
	float MagDist;

	bool hasTeleported = false;
	double teleportTime = 0.0;
	float Timer;

public:
	Movement(Object *pComponent); // move
	void SetVelocity(glm::vec3 pVelocity) // set speed
	{
		Velocity = pVelocity; // velocity from shape 1 gets turn into acc for shape 2
	}
	glm::vec3 GetVelocity()
	{
		return Velocity;
	}
	void SetAcceleration(glm::vec3 pAcceleration) // set speed
	{
		Acceleration = pAcceleration; // acc 
	}
	void SetHasRocketFired(bool b)
	{
		HasRocketFired = b;
	}
	glm::vec3 GetAcceleration()
	{
		return Acceleration;
	}
	glm::vec3 GetAim()
	{
		return Aim;
	}
	float GetMass()
	{
		return Mass;
	}
	float GetRocketPower()
	{
		return RocketPower;
	}
	void Create(); //starting
	void Delete();
	void Update(double DeltaTime); //updating
	void Render(Shader & shader);

	glm::vec3 CalcBlackHole(glm::vec3 Position, glm::vec3 HolePosition);

	bool getTeleported() 
	{
		return hasTeleported;
	}

	void setTeleported(bool teleport) 
	{
		hasTeleported = teleport;
		if (teleport = true)
		{
			teleportTime = glfwGetTime();
		}
	}


};
#endif
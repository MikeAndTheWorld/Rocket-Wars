#include "Components\Sub-Components\Movement.h"
#include "Window.h"
#include <cstdio>

Movement::Movement(Object *pComponent)
{
	m_ObjectComponent = pComponent;
	m_CompName = "Movement";
}
void Movement::Create() //starting
{
	down = false;
	////speed
	MovementSpeed = 0.005f;

	//starting pos
	MovementY = 0.0f;
	MovementZ = 0.0f;
	MovementX = 0.0f;

	//new pos
	MovementPos.y = MovementY;
	MovementPos.z = MovementZ;
	MovementPos.x = MovementX;

	// friction
	DragForce.x = 0.4f;
	DragForce.y	= 0.4f;
	DragForce.z	= 0.4f;

	//starting Acceleration
	Acceleration.x = 0.0f;
	Acceleration.y = 0.0f;
	Acceleration.z = 0.0f;

	// starting velocity
	Velocity.x = 0.0f;
	Velocity.y = 0.0f;
	Velocity.z = 0.0f;
	
	//starting rk4
	k1.x = 0.0f;
	k1.y = 0.0f;
	k1.z = 0.0f;
	//k2
	k2.x = 0.0f;
	k2.y = 0.0f;
	k2.z = 0.0f;
	//k3
	k3.x = 0.0f;
	k3.y = 0.0f;
	k3.z = 0.0f;
	//k4
	k4.x = 0.0f;
	k4.y = 0.0f;
	k4.z = 0.0f;
	
	// Displacement
	Displacement.x = 0.0f;
	Displacement.y = 0.0f;
	Displacement.z = 0.0f;

	//Gravity
	GravitationalPull.x = 0.0f;
	GravitationalPull.y = 0.0f;
	GravitationalPull.z = 0.0f;
	GravityDistance.x = 0.0f;
	GravityDistance.y = 0.0f;
	GravityDistance.z = 0.0f;
	GravityForce = glm::vec3(0, 0, 0);

	//Aim
	Aim.x = 0.0f;
	Aim.y = 0.0f;
	Aim.z = 0.0f;

	//acceleration of rocket
	RocketPower = 0.0f;
	//counter
	MovementCounter = 0;

	//Mass = 0.98f;
	Mass = 1.0;
	MagDist = 0.0f;
	//timer
	Timer = 0.0;
	//has fire
	HasRocketFired = false;
}

void Movement::Update(double DeltaTime)//updating
{

	if (teleportTime > 0.0) {
		if (glfwGetTime() - teleportTime > 0.5) {
			teleportTime = 0.0;
			hasTeleported = false;
		}
	}

	//k1
	//speed
	(float)Velocity.x = (float)Velocity.x + ((float)Acceleration.x * (float)DeltaTime); // the new velocity X
	(float)Velocity.y = (float)Velocity.y + ((float)Acceleration.y * (float)DeltaTime); // the new velocity y
	(float)Velocity.z = (float)Velocity.z + ((float)Acceleration.z * (float)DeltaTime); // the new velocity Z

	      //f           //h
	k1 = (Velocity * (float)DeltaTime);

	//k2
	//speed      // y                            //t
	k2.x = Velocity.x + (k1.x * 0.5f) + (Acceleration.x * (0.5f * DeltaTime)); // the new velocity X
	k2.y = Velocity.y + (k1.y * 0.5f) + (Acceleration.y * (0.5f * DeltaTime)); // the new velocity y
	k2.z = Velocity.z + (k1.z * 0.5f) + (Acceleration.z * (0.5f * DeltaTime)); // the new velocity Z

	k2 = (k2 * (float)DeltaTime);

	//k3
	//speed      // y                            //t
	k3.x = Velocity.x + (k2.x * 0.5f) + (Acceleration.x * (0.5f * DeltaTime)); // the new velocity X
	k3.y = Velocity.y + (k2.y * 0.5f) + (Acceleration.y * (0.5f * DeltaTime)); // the new velocity y
	k3.z = Velocity.z + (k2.z * 0.5f) + (Acceleration.z * (0.5f * DeltaTime)); // the new velocity Z

	k3 = (k3 * (float)DeltaTime);

	//k4
	//speed      // y                            //t
	k4.x = Velocity.x + k3.x + (Acceleration.x * DeltaTime); // the new velocity X
	k4.y = Velocity.y + k3.y + (Acceleration.y * DeltaTime); // the new velocity y
	k4.z = Velocity.z + k3.z + (Acceleration.z * DeltaTime); // the new velocity Z

	k4 = (k4 * (float)DeltaTime);

	///
	Acceleration = glm::vec3(0.0f, 0.0f, 0.0f);
	///

	//pos rk4
	Displacement.x = Velocity.x + (k1.x + (2.0f * k2.x) + (2.0f * k3.x) + k4.x) * DeltaTime / 6;
	Displacement.y = Velocity.y + (k1.y + (2.0f * k2.y) + (2.0f * k3.y) + k4.y) * DeltaTime / 6;
	Displacement.z = Velocity.z + (k1.z + (2.0f * k2.z) + (2.0f * k3.z) + k4.z) * DeltaTime / 6;	
	//drag to slow rocket
	Velocity.x = Velocity.x -(Velocity.x * DragForce.x * Mass * DeltaTime);
	Velocity.y = Velocity.y -(Velocity.y * DragForce.y * Mass * DeltaTime);
	Velocity.z = Velocity.z -(Velocity.z * DragForce.z * Mass * DeltaTime);


	
	//// Y lock
	//if (Velocity.y >= 2.0) //reset back to 0 when speed is lowered
	//{
	//	Velocity.y = 2.0; //stopped
	//}
	//else if (Velocity.y <= -2.0) //reset back to 0 when speed is lowered
	//{
	//	Velocity.y = -2.0; //stopped
	//}
	//else
	//{
	//	Velocity.y = Velocity.y;
	//}
	//// X lock
	//if (Velocity.x >= 2.0) //reset back to 0 when speed is lowered
	//{
	//	Velocity.x = 2.0; //stopped
	//}
	//else if (Velocity.x <= -2.0) //reset back to 0 when speed is lowered
	//{
	//	Velocity.x = -2.0; //stopped
	//}
	//else
	//{
	//	Velocity.x = Velocity.x;
	//}
	// Z lock
	//if (Velocity.z >= 2.0) //reset back to 0 when speed is lowered
	//{
	//	Velocity.z = 2.0; //stopped
	//}
	//else if (Velocity.z <= -2.0) //reset back to 0 when speed is lowered
	//{
	//	Velocity.z = -2.0; //stopped
	//}
	//else
	//{
	//	Velocity.z = Velocity.z;
	//}
	//
	if (MovementPos == glm::vec3(0.0f, 4.4f, 18.50f))
	{
		if (glfwGetKey(Window::getInstance()->getWindow(), GLFW_KEY_W) == GLFW_PRESS) // forward
		{
			down = true;
			if (RocketPower < 200.0f)
			{
				RocketPower = RocketPower + 1.0f;
			}
			else
			{
				RocketPower = 200.0f;
			}
		}

				//glm::vec3 dist( - m_ObjectComponent->getComponent<Transform>()->GetPos())
		
	}
	if (down == true && glfwGetKey(Window::getInstance()->getWindow(), GLFW_KEY_W) == GLFW_RELEASE)
	{
		HasRocketFired = true;
		down = false;
		Acceleration.x = m_ObjectComponent->getComponent<Transform>()->GetAim().x * RocketPower;
		Acceleration.y = m_ObjectComponent->getComponent<Transform>()->GetAim().y * RocketPower;
		Acceleration.z = m_ObjectComponent->getComponent<Transform>()->GetAim().z * RocketPower;
		RocketPower = 0.0f;
	}
	if (HasRocketFired == true)
	{
		
		GravitationalPull = glm::vec3(0.0f, 0.0f, 0.0f);

		GravitationalPull -= CalcBlackHole(glm::vec3(0.0f, 25.0f, 18.50f), MovementPos); // black hole 1
		GravitationalPull -= CalcBlackHole(glm::vec3(-40.0f, 30.0f, 18.50f), MovementPos); // black hole 2

		Velocity += GravitationalPull * float(DeltaTime);
		m_ObjectComponent->getComponent<Transform>()->SetAim(glm::normalize(Velocity));
	}
		
	//Aim = m_ObjectComponent->getComponent<Transform>()->GetAim();
	MovementPos = m_ObjectComponent->getComponent<Transform>()->GetPos() + Displacement;//+ (Aim * Displacement);
	

	//if (Velocity.x < 0.08 && Velocity.x > -0.08) //reset back to 0 when speed is lowered
	//{
	//	Velocity.x = 0;
	//}
	//if (Velocity.y < 0.08 && Velocity.y > -0.08) //reset back to 0 when speed is lowered
	//{
	//	Velocity.y = 0; //stopped
	//}
	//if (Velocity.z < 0.08 && Velocity.z > -0.08) //reset back to 0 when speed is lowered
	//{
	//	Velocity.z = 0;
	//}

	//Timer += DeltaTime;

	//if (Timer >= 16.0f)
	//{
	//	cout << "timer" << Timer << endl;
	//	cout << "Displacement:" << MovementPos.y << endl;
	//}
	if (glm::distance(glm::vec3(0.0f, 4.4f, 18.50f), MovementPos) > 125 && HasRocketFired == true) // fired out of range reset
	{
		MovementPos = glm::vec3(0.0f, 4.4f, 18.50f);
		m_ObjectComponent->getComponent<Transform>()->SetPos(glm::vec3(0.0f, 4.4f, 18.50f));
		SetHasRocketFired(false);
		SetVelocity(glm::vec3(0.0f, 0.0f, 0.0f));
	}																	 

	m_ObjectComponent->getComponent<Transform>()->SetPos(MovementPos);
	
}
void Movement::Render(Shader & shader)
{

}
void Movement::Delete() 
{

}

glm::vec3 Movement::CalcBlackHole(glm::vec3 Position, glm::vec3 HolePosition) {
	glm::vec3 grav = glm::normalize(HolePosition - Position);
	MagDist = glm::distance(HolePosition, Position);

	return  (grav * 100.0f * Mass) / (MagDist * MagDist); // F= G m1m2/ r^2 Newton’s law of universal gravitation

	
}
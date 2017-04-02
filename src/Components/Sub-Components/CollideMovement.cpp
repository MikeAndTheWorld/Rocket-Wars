#include "Components\Sub-Components\CollideMovement.h"
#include "Window.h"
#include <cstdio>

CollideMovement::CollideMovement(Object *pComponent)
{
	m_ObjectComponent = pComponent;
	m_CompName = "CollideMovement";
}
void CollideMovement::Create() //starting
{
	//speed
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
	DragForce.y = 0.4f;
	DragForce.z = 0.4f;

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

	//Aim
	Aim.x = 0.0f;
	Aim.y = 0.0f;
	Aim.z = 0.0f;

	//acceleration of ship
	ShipSpeed = 0.0f;
}

void CollideMovement::Update(double DeltaTime)//updating
{
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

	//pos rk4
	Displacement.x = Velocity.x + (k1.x + (2.0f * k2.x) + (2.0f * k3.x) + k4.x) * DeltaTime / 6;
	Displacement.y = Velocity.y + (k1.y + (2.0f * k2.y) + (2.0f * k3.y) + k4.y) * DeltaTime / 6;
	Displacement.z = Velocity.z + (k1.z + (2.0f * k2.z) + (2.0f * k3.z) + k4.z) * DeltaTime / 6;
	//drag to slow rocket
	Velocity.x = Velocity.x - (Velocity.x * DragForce.x * 0.98f * DeltaTime);
	Velocity.y = Velocity.y - (Velocity.y * DragForce.y * 0.98f * DeltaTime);
	Velocity.z = Velocity.z - (Velocity.z * DragForce.z * 0.98f * DeltaTime);

	if (Velocity.y < 0.1 && Velocity.y > -0.1) //reset back to 0 when speed is lowered
	{
		Velocity.y = 0; //stopped
	}
	if (Velocity.x < 0.1 && Velocity.x > -0.1) //reset back to 0 when speed is lowered
	{
		Velocity.x = 0;
	}
	if (Velocity.z < 0.1 && Velocity.z > -0.1) //reset back to 0 when speed is lowered
	{
		Velocity.z = 0;
	}

	// Y lock
	if (Velocity.y >= 2.0) //reset back to 0 when speed is lowered
	{
		Velocity.y = 2.0; //stopped
	}
	else if (Velocity.y <= -2.0) //reset back to 0 when speed is lowered
	{
		Velocity.y = -2.0; //stopped
	}
	else
	{
		Velocity.y = Velocity.y;
	}
	// X lock
	if (Velocity.x >= 2.0) //reset back to 0 when speed is lowered
	{
		Velocity.x = 2.0; //stopped
	}
	else if (Velocity.x <= -2.0) //reset back to 0 when speed is lowered
	{
		Velocity.x = -2.0; //stopped
	}
	else
	{
		Velocity.x = Velocity.x;
	}
	// Z lock
	if (Velocity.z >= 2.0) //reset back to 0 when speed is lowered
	{
		Velocity.z = 2.0; //stopped
	}
	else if (Velocity.z <= -2.0) //reset back to 0 when speed is lowered
	{
		Velocity.z = -2.0; //stopped
	}
	else
	{
		Velocity.z = Velocity.z;
	}

	//Aim = m_ObjectComponent->getComponent<Transform>()->GetAim();
	Displacement.z = 0.4 - (DragForce.z * DeltaTime / 60);
	MovementPos = m_ObjectComponent->getComponent<Transform>()->GetPos() + (Aim * Displacement);
	if (Velocity.x >= 0 || Velocity.y >= 0 || Velocity.z >= 0) {
	}

	/*cout << Aim.x << " " << Aim.y << " " << Aim.z << endl;*/

	m_ObjectComponent->getComponent<Transform>()->SetPos(MovementPos);
	/*cout << Displacement.x << " " << Displacement.y << " " << Displacement.z << " " << Acceleration.x << " " << Acceleration.y << " " << Acceleration.z << endl
	<< Velocity.x << " " << Velocity.y << " " << Velocity.z << endl;*/

}

void CollideMovement::Render(Shader & shader)
{

}
void CollideMovement::Delete()
{

}
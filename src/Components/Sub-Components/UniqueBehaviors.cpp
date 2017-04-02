#include "Components\Sub-Components\UniqueBehaviors.h"
#include "Window.h"
#include <cstdio>
#include <time.h> 



BoxCollisionActivity::BoxCollisionActivity(Object *pComponent)
{
	m_ObjectComponent = pComponent;
	m_CompName = "BoxCollisionActivity";
	Gen = false;
}
void BoxCollisionActivity::Create() //starting
{
	
}

void BoxCollisionActivity::Update(double DeltaTime)//updating
{

}
void BoxCollisionActivity::Render(Shader & shader)
{

}
void BoxCollisionActivity::Delete()
{

}

void BoxCollisionActivity::PostCollision(Object * collidedObject) 
{
	if (m_ObjectComponent->CheckComponentExists<Transform>())
	{
		if (Gen == false)
		{
			Zz = rand() % 2 + 1;
			Gen = true;
		}
		float Z = 0.0f;
		if (Zz == 1)
		{
			Z = -1.0f;
		}
		else
		{
			Z = 1.0f;
		}

		/*glm::vec3 A(0.0f, 0.0f, Z);
		if (collidedObject->CheckComponentExists<Movement>())
		{
			A.x = collidedObject->getComponent<Movement>()->GetAim().x;
			A.y = collidedObject->getComponent<Movement>()->GetAim().y;
		}
		else
		{
			A.x = collidedObject->getComponent<CollideMovement>()->GetAim().x;
			A.y = collidedObject->getComponent<CollideMovement>()->GetAim().y;
		}
		m_ObjectComponent->getComponent<Transform>()->SetAim(A);*/
		
		glm::vec3 hitPos = m_ObjectComponent->getComponent<Transform>()->GetPos();
		glm::vec3 CollidePos = collidedObject->getComponent<Transform>()->GetPos();

		glm::vec3 dir = glm::normalize(hitPos - CollidePos);
		dir.z = Z;
		m_ObjectComponent->getComponent<CollideMovement>()->SetAim(dir);

		glm::vec3 V;
		if (collidedObject->CheckComponentExists<Movement>())
		{
			V = collidedObject->getComponent<Movement>()->GetVelocity();
		}
		else
		{
			V = collidedObject->getComponent<CollideMovement>()->GetVelocity();
		}
		m_ObjectComponent->getComponent<CollideMovement>()->SetVelocity(V);
	}
}

/////////////////////////////////////////////////


ShipCollisionActivity::ShipCollisionActivity(Object *pComponent)
{
	m_ObjectComponent = pComponent;
	m_CompName = "ShipCollisionActivity";
	Gen = false;
}
void ShipCollisionActivity::Create() //starting
{

}

void ShipCollisionActivity::Update(double DeltaTime)//updating
{

}
void ShipCollisionActivity::Render(Shader & shader)
{

}
void ShipCollisionActivity::Delete()
{

}

void ShipCollisionActivity::PostCollision(Object * collidedObject)
{
	int Win = 0;

	/*if (m_ObjectComponent->CheckComponentExists<Transform>())
	{
		if (Gen == false)
		{
			Zz = rand() % 2 + 1;
			Gen = true;
		}
		float Z = 0.0f;
		if (Zz == 1)
		{
			Z = -1.0f;
		}
		else
		{
			Z = 1.0f;
		}

		glm::vec3 A(0.0f, 0.0f, Z);
		if (collidedObject->CheckComponentExists<Movement>())
		{
			A.x = collidedObject->getComponent<Movement>()->GetAim().x;
			A.y = collidedObject->getComponent<Movement>()->GetAim().y;
		}
		else
		{
			A.x = collidedObject->getComponent<CollideMovement>()->GetAim().x;
			A.y = collidedObject->getComponent<CollideMovement>()->GetAim().y;
		}
		m_ObjectComponent->getComponent<Transform>()->SetAim(A);
		glm::vec3 V;
		if (collidedObject->CheckComponentExists<Movement>())
		{
			V = collidedObject->getComponent<Movement>()->GetVelocity();
		}
		else
		{
			V = collidedObject->getComponent<CollideMovement>()->GetVelocity();
		}
		m_ObjectComponent->getComponent<CollideMovement>()->SetVelocity(V);
	}*/
}

/////////////////////////////////////////////////


BlackHoleCollisionActivity::BlackHoleCollisionActivity(Object *pComponent)
{
	m_ObjectComponent = pComponent;
	m_CompName = "BlackHoleCollisionActivity";
}
void BlackHoleCollisionActivity::Create() //starting
{

}

void BlackHoleCollisionActivity::Update(double DeltaTime)//updating
{

}
void BlackHoleCollisionActivity::Render(Shader & shader)
{

}
void BlackHoleCollisionActivity::Delete()
{

}

void BlackHoleCollisionActivity::PostCollision(Object * collidedObject)
{
	if (m_ObjectComponent->CheckComponentExists<Transform>())
	{
		//glm::vec3 Dist = m_ObjectComponent->getComponent<Transform>()->GetPos() - collidedObject->getComponent<Transform>()->GetPos();

		//collidedObject->getComponent<Movement>()->GetAcceleration(); //vec 3 acc
		//collidedObject->getComponent<Movement>()->GetMass();// float mass

		collidedObject->getComponent<Movement>()->SetVelocity(glm::vec3(0.0f, 0.0f, 0.0f));
		collidedObject->getComponent<Movement>()->SetHasRocketFired(false);
		collidedObject->getComponent<Transform>()->SetPos(glm::vec3(0.0f, 4.4f, 18.50f));
	}
}

/////////////////////////////////////////////////


WormHoleCollisionActivity::WormHoleCollisionActivity(Object *pComponent)
{
	m_ObjectComponent = pComponent;
	m_CompName = "WormHoleCollisionActivity";
}
void WormHoleCollisionActivity::Create() //starting
{

}

void WormHoleCollisionActivity::Update(double DeltaTime)//updating
{

}
void WormHoleCollisionActivity::Render(Shader & shader)
{

}
void WormHoleCollisionActivity::Delete()
{

}

void WormHoleCollisionActivity::PostCollision(Object * collidedObject)
{
	//glm::vec3 Dist = glm::normalize(collidedObject->getComponent<Transform>()->GetPos() - m_ObjectComponent->getComponent<Transform>()->GetPos());
	if (collidedObject->getComponent<Movement>()->getTeleported() == false) {
		collidedObject->getComponent<Movement>()->setTeleported(true);
		float distance = glm::distance(collidedObject->getComponent<Transform>()->GetPos(), m_ObjectComponent->getComponent<Transform>()->GetPos());
		if (distance == 0.0f)
		{
			return;
		}

		if (m_ObjectComponent->getComponent<Transform>()->GetPos() == glm::vec3(12.0f, 15.0f, 18.50f))
		{
			collidedObject->getComponent<Transform>()->SetPos(glm::vec3(-10.0f, 30.0f, 18.50f));
		}
		if (m_ObjectComponent->getComponent<Transform>()->GetPos() == glm::vec3(-10.0f, 30.0f, 18.50f))
		{
			collidedObject->getComponent<Transform>()->SetPos(glm::vec3(12.0f, 15.0f, 18.50f));
		}
	}
}


/////////////////////////////////////////////////


EmptyCollisionActivity::EmptyCollisionActivity(Object *pComponent)
{
	m_ObjectComponent = pComponent;
	m_CompName = "EmptyCollisionActivity";
}
void EmptyCollisionActivity::Create() //starting
{

}

void EmptyCollisionActivity::Update(double DeltaTime)//updating
{

}
void EmptyCollisionActivity::Render(Shader & shader)
{

}
void EmptyCollisionActivity::Delete()
{

}

void EmptyCollisionActivity::PostCollision(Object * collidedObject)
{

}
#include "Components\Sub-Components\ConvexHull.h"
#include "Window.h"
#include <cstdio>

ConvexHull::ConvexHull(Object *pComponent)
{
	m_ObjectComponent = pComponent;
	m_CompName = "ConvexHull";

	/*pComponent->CheckComponentExists<ConvexHull>();*/
	collisionBehaviour = new EmptyCollisionActivity(pComponent);
}
void ConvexHull::Create() //starting
{	
	model = m_ObjectComponent->getComponent<Model>();
	MidPoints = m_ObjectComponent->getComponent<Transform>()->GetTurningPoint();

	//get model's point in size
	for (int i = 0; i < model->GetVertices().size(); i++)
	{
		//max
		if (model->GetVertices()[i].x > MaxPoints.x)
		{
			MaxPoints.x = model->GetVertices()[i].x;
		}
		if (model->GetVertices()[i].y > MaxPoints.y)
		{
			MaxPoints.y = model->GetVertices()[i].y;
		}
		if (model->GetVertices()[i].z > MaxPoints.z)
		{
			MaxPoints.z = model->GetVertices()[i].z;
		}
		//min
		if (model->GetVertices()[i].x < MinPoints.x)
		{
			MinPoints.x = model->GetVertices()[i].x;
		}
		if (model->GetVertices()[i].y < MinPoints.y)
		{
			MinPoints.y = model->GetVertices()[i].y;
		}
		if (model->GetVertices()[i].z < MinPoints.z)
		{
			MinPoints.z = model->GetVertices()[i].z;
		}
	}
	// works out the max and min from the rotation point
	MaxPoints = MaxPoints - MidPoints;
	MinPoints = MinPoints - MidPoints;
	// get postion of the max and min on a moving model
	//MaxPoints = MaxPoints + m_ObjectComponent->getComponent<Transform>()->GetPos();
	//MinPoints = MinPoints + m_ObjectComponent->getComponent<Transform>()->GetPos();
	//PointA1 = MaxPoints;
	//PointB1 = MinPoints;
	////back
	//PointA2 = glm::vec3(PointA1.x, PointB1.y, PointA1.z);
	//PointA3 = glm::vec3(PointB1.x, PointB1.y, PointA1.z);
	//PointA4 = glm::vec3(PointB1.x, PointA1.y, PointA1.z);
	////front
	//PointB2 = glm::vec3(PointA1.x, PointB1.y, PointB1.z);
	//PointB3 = glm::vec3(PointA1.x, PointA1.y, PointB1.z);
	//PointB4 = glm::vec3(PointB1.x, PointA1.y, PointB1.z);

}	
void ConvexHull::Update(double DeltaTime)//updating
{

}
void ConvexHull::Render(Shader & shader)
{

}
void ConvexHull::Delete()
{

}

glm::vec3 ConvexHull::GetMaxPoint() // get max
{
	return MaxPoints;
}
glm::vec3 ConvexHull::GetMinPoint() // get min
{
	return MinPoints;
}
glm::vec3 ConvexHull::GetMidPoint() // get mid
{
	return MidPoints;
}
glm::vec3 ConvexHull::GetRotatePoint() // get rotate
{
	return m_ObjectComponent->getComponent<Transform>()->GetRotate();
}
glm::vec3 ConvexHull::GetPositionPoint() // get pos
{
	return m_ObjectComponent->getComponent<Transform>()->GetPos();
}
glm::vec3 ConvexHull::GetScalePoint() // get scale
{
	return m_ObjectComponent->getComponent<Transform>()->GetScale();
}
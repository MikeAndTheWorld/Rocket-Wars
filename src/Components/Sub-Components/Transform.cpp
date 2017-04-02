#include"Components\Sub-Components\Transform.h"

Transform::Transform(Object *pComponent) // tranform
{
	m_ObjectComponent = pComponent;
	m_CompName = "TRANSfORM";
}
void Transform::Update(double DeltaTime)
{

}
void Transform::Delete()
{
	delete this;
}
void Transform::Create()
{
	HasMoved = true;
}

void Transform::Render(Shader &shader) 
{

}
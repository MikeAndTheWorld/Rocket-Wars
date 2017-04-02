#include "Components\Sub-Components\Animation.h"
#include "Window.h"
#include <cstdio>

Animation::Animation(Object *pComponent)
{
	m_ObjectComponent = pComponent;
	m_CompName = "Animation";
}
void Animation::Create() //starting
{
	AnimationAngle.x = 0.0f;
	AnimationAngle.y = 0.0f;
	AnimationAngle.z = 0.0f;
	AnimationHorizontalAngle = 3.1415f;
	AnimationVerticalAngle = 0.0f;
}

void Animation::Update(double DeltaTime)//updating
{
	AnimationAngle.x = AnimationVerticalAngle;
	AnimationAngle.y = AnimationHorizontalAngle;
	AnimationAngle.z = 0.0f /*3.1415f / 2.0f*/;

	//AnimationVerticalAngle = AnimationVerticalAngle - 3.1415f * DeltaTime;
	AnimationHorizontalAngle = AnimationHorizontalAngle - 3.1415f * DeltaTime;
	m_ObjectComponent->getComponent<Transform>()->SetRotate(glm::vec3(AnimationAngle.x, AnimationAngle.y, AnimationAngle.z));

}
void Animation::Render(Shader & shader)
{

}
void Animation::Delete()
{

}
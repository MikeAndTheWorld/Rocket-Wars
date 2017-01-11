#include"Components\Sub-Components\Transform.h"

TransformComponent::TransformComponent(Object *pComponent)
{
	m_ObjectComponent = pComponent;
	m_CompName = "TRANSfORM";
}
void TransformComponent::Update(double DeltaTime)
{
	if (HasMoved == true)
	{
			m_Model = glm::translate(m_Model, m_Pos);  // First translate (transformations are: scale happens first, then rotation and then final translation happens; reversed order)

			m_Model = glm::translate(m_Model, glm::vec3(0.5f * m_Scale.x, 0.5f * m_Scale.y, 0.5f * m_Scale.z)); // Move origin of rotation to center of quad
			m_Model = glm::rotate(m_Model, m_Rotate.x, glm::vec3(1.0f, 0.0f, 0.0f)); // Then rotate X
			m_Model = glm::rotate(m_Model, m_Rotate.y, glm::vec3(0.0f, 1.0f, 0.0f)); // Then rotate Y
			m_Model = glm::rotate(m_Model, m_Rotate.z, glm::vec3(0.0f, 0.0f, 1.0f)); // Then rotate Z
			m_Model = glm::translate(m_Model, glm::vec3(-0.5f * m_Scale.x, -0.5f * m_Scale.y, -0.5f * m_Scale.z)); // Move origin back

			m_Model = glm::scale(m_Model, m_Scale); // Last scale
			HasMoved = false;
	}

}
void TransformComponent::Delete()
{
	delete this;
}
void TransformComponent::Create()
{
	HasMoved = true;
}
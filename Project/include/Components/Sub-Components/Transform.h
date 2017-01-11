#ifndef TRANSFORM_COMP_H
#define TRANSFORM_COMP_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include <gtx/transform.hpp>

#include "Components\Components.h"

using namespace std;

class TransformComponent : public Component
{
private:
	bool HasMoved = false;
	glm::vec3 m_Pos = glm::vec3(0.0f, 0.0f, 0.0f); //position
	glm::vec3 m_Scale = glm::vec3(1.0f, 1.0f, 1.0f); //size
	glm::vec3 m_Rotate = glm::vec3(0.0f, 0.0f, 0.0f); // rotation
	glm::mat4 m_Model; //model
	glm::vec3 m_Direct; // direction

public:
	TransformComponent(Object * pComponent);

	void Delete(); //destorying
	void Create(); //starting
	void Update(double DeltaTime); //updating

	glm::vec3 GetPos()
	{
		return m_Pos;
	}

	glm::vec3 GetScale()
	{
		return m_Scale;
	}

	glm::vec3 GetRotate()
	{
		return m_Rotate;
	}
	
	glm::vec3 GetDirect()
	{
		return m_Direct;
	}

	void SetPos(glm::vec3 pPos)
	{
		m_Pos = pPos;
		HasMoved = true;
	}
	void SetScale(glm::vec3 pScale)
	{
		m_Scale = pScale;
		HasMoved = true;
	}
	void SetRotate(glm::vec3 pRotate)
	{
		m_Rotate = pRotate;
		HasMoved = true;
	}
	void SetDirect(glm::vec3 pDirect)
	{
		m_Direct = pDirect;
		HasMoved = true;
	}

};
#endif


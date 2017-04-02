#ifndef TRANSFORM_COMP_H
#define TRANSFORM_COMP_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include <gtx/transform.hpp>

#include "Components\Components.h"

using namespace std;
class Object;

class Transform : public Component
{
private:
	bool HasMoved = false;
	glm::vec3 m_Pos = glm::vec3(0.0f, 0.0f, 0.0f); //position
	glm::vec3 m_Scale = glm::vec3(1.0f, 1.0f, 1.0f); //size
	glm::vec3 m_Rotate = glm::vec3(0.0f, 0.0f, 0.0f); // rotation
	glm::mat4 m_Model = glm::mat4(1.0f); //model
	glm::vec3 m_Direct; // direction
	glm::vec3 m_AD; // left and right

	glm::vec3 Aiming;
	glm::vec3 TurningPoint = glm::vec3(0.0f, 0.0f, 0.0f);

public:
	Transform(Object * pComponent);

	void Delete(); //destorying
	void Create(); //starting
	void Update(double DeltaTime); //updating
	void Render(Shader & shader);

	glm::vec3 GetTurningPoint() // get point to rotate
	{
		return TurningPoint;
	}

	glm::vec3 GetPos() // get pos
	{
		return m_Pos;
	}

	glm::vec3 GetScale() // get scale
	{
		return m_Scale;
	}

	glm::vec3 GetRotate() // get rotate
	{
		return m_Rotate;
	}

	glm::vec3 GetDirect() // get direction 
	{
		return m_Direct;
	}
	glm::vec3 GetAim() // get aim
	{
		return Aiming;
	}

	glm::vec3 GetAD() // left and right
	{
		return m_AD;
	}
	void SetPos(glm::vec3 pPos) // set pos
	{
		m_Pos = pPos;
		HasMoved = true;
	}
	void SetTurningPoint(glm::vec3 pTurningPoint) // set TurningPoint
	{
		TurningPoint = pTurningPoint;
		HasMoved = true;
	}
	void SetScale(glm::vec3 pScale) // set scale
	{
		m_Scale = pScale;
		HasMoved = true;
	}
	void SetRotate(glm::vec3 pRotate) // set rotate
	{
		m_Rotate = pRotate;
		HasMoved = true;
	}
	void SetDirect(glm::vec3 pDirect) // set direction
	{
		m_Direct = pDirect;
		HasMoved = true;
	}
	void SetAim(glm::vec3 pAim) // set aim
	{
		Aiming = pAim;
		SetRotate(glm::vec3(GetRotate().x, GetRotate().y, (-acosf(pAim.x / 1))+3.1415f/2.0f));

		HasMoved = true;
	}
	void SetAD(glm::vec3 pAD) // left and right set
	{
		m_AD = pAD;
		HasMoved = true;
	}

	glm::mat4 getModelMatrix() {

		m_Model = glm::mat4(1.0f); // model matrix
		m_Model = glm::translate(m_Model, m_Pos);  // First translate (transformations are: scale happens first, then rotation and then final translation happens; reversed order)

		//m_Model = glm::translate(m_Model, glm::vec3(0.5f * m_Scale.x, 0.5f * m_Scale.y, 0.5f * m_Scale.z)); // Move origin of rotation to center of quad
		m_Model = glm::translate(m_Model,TurningPoint);
		m_Model = glm::rotate(m_Model, m_Rotate.x, glm::vec3(1.0f, 0.0f, 0.0f)); // Then rotate X
		m_Model = glm::rotate(m_Model, m_Rotate.y, glm::vec3(0.0f, 1.0f, 0.0f)); // Then rotate Y
		m_Model = glm::rotate(m_Model, m_Rotate.z, glm::vec3(1.0f, 0.0f, 0.0f)); // Then rotate Z
		m_Model = glm::translate(m_Model,-TurningPoint);
		//m_Model = glm::translate(m_Model, glm::vec3(-0.5f * m_Scale.x, -0.5f * m_Scale.y, -0.5f * m_Scale.z)); // Move origin back
		m_Model = glm::scale(m_Model, m_Scale); // Last scale


		return m_Model; // return model
	}

};
#endif


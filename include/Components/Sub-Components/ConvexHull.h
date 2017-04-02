#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include <gtx/transform.hpp>
#include <math.h>

//#include "Components\Components.h"
//#include "Rendering\Shaders.h"
//#include "Components\Sub-Components\Transform.h"
#include "Model.h"
#include "UniqueBehaviors.h"
#include "Components\Sub-Components\Collided.h"


class UniqueBehaviours;


class ConvexHull: public Component
{
private:
	Transform * transform;
	Model * model;
	GLFWwindow * window;

	glm::vec3 MaxPoints = glm::vec3(0.0f,0.0f,0.0f);
	glm::vec3 MinPoints = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 MidPoints = glm::vec3(0.0f, 0.0f, 0.0f);

	////max side
	//glm::vec3 PointA1 = glm::vec3(0.0f, 0.0f, 0.0f);
	//glm::vec3 PointA2 = glm::vec3(0.0f, 0.0f, 0.0f);
	//glm::vec3 PointA3 = glm::vec3(0.0f, 0.0f, 0.0f);
	//glm::vec3 PointA4 = glm::vec3(0.0f, 0.0f, 0.0f);
	////min side
	//glm::vec3 PointB1 = glm::vec3(0.0f, 0.0f, 0.0f);
	//glm::vec3 PointB2 = glm::vec3(0.0f, 0.0f, 0.0f);
	//glm::vec3 PointB3 = glm::vec3(0.0f, 0.0f, 0.0f);
	//glm::vec3 PointB4 = glm::vec3(0.0f, 0.0f, 0.0f);

	Collided * collisionBehaviour;

public:
	ConvexHull(Object *pComponent); // move

	glm::vec3 GetMaxPoint();
	glm::vec3 GetMinPoint();
	glm::vec3 GetMidPoint();
	glm::vec3 GetRotatePoint();
	glm::vec3 GetPositionPoint();
	glm::vec3 GetScalePoint();

	void Create(); //starting
	void Delete();
	void Update(double DeltaTime); //updating
	void Render(Shader & shader);

	void setBehaviour(Collided * behaviour) {
		collisionBehaviour = behaviour;
	}

	Collided * getBehaviour() {
		return collisionBehaviour;
	}


};
#endif

#ifndef COLLISION_H_
#define COLLISION_H_

#include "Object.h"
#include <vector>
#include "Components\Sub-Components\Transform.h"
#include "Components\Sub-Components\CollideMovement.h"
#include "Components\Sub-Components\Movement.h"
#include "Components\Sub-Components\ConvexHull.h"

class Object;

class Collision
{
private:
	//box 1
	//max side
	glm::vec3 PointA1 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 PointA2 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 PointA3 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 PointA4 = glm::vec3(0.0f, 0.0f, 0.0f);
	//min side
	glm::vec3 PointA5 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 PointA6 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 PointA7 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 PointA8 = glm::vec3(0.0f, 0.0f, 0.0f);
	//box 2
	//max side
	glm::vec3 PointB1 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 PointB2 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 PointB3 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 PointB4 = glm::vec3(0.0f, 0.0f, 0.0f);
	//min side
	glm::vec3 PointB5 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 PointB6 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 PointB7 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 PointB8 = glm::vec3(0.0f, 0.0f, 0.0f);
	//M sum Box

	//GJK p
	glm::vec3 PointP1 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 PointP2 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 PointP3 = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 PointP4 = glm::vec3(0.0f, 0.0f, 0.0f);

	glm::vec3 MaxA = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 MinA = glm::vec3(0.0f, 0.0f, 0.0f);

	glm::vec3 MaxB = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 MinB = glm::vec3(0.0f, 0.0f, 0.0f);
	//boxes points AABB
	vector <glm::vec3> A;
	vector <glm::vec3> B;

	glm::vec3 D = glm::vec3(0.0f, 0.0f, 0.0f);

	vector <glm::vec3> Simplex;


public:
	Transform * transform;
	Object * object;
	Movement * movement;
	CollideMovement * collideMovement;

	Collision();
	bool HasHit(ConvexHull * HullA, ConvexHull * HullB);
};
#endif


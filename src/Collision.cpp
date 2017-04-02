#include "Collision.h"
#include <gtc\type_ptr.hpp>


using namespace std;

Collision::Collision()
{

}
bool Collision::HasHit(ConvexHull * HullA, ConvexHull * HullB)
{
	A.clear();
	B.clear();
	//box 1
	PointA1 = HullA->GetMaxPoint();
	PointA5 = HullA->GetMinPoint();
	//scale
	PointA1 = PointA1 * HullA->GetScalePoint();
	PointA5 = PointA5 * HullA->GetScalePoint();
	//rotate points A1 and A5 by objectA rotation
	glm::mat4 rotationmatrix(1.0f); // model matrix
	rotationmatrix = glm::rotate(rotationmatrix, HullA->GetRotatePoint().x, glm::vec3(1.0f, 0.0f, 0.0f)); // Then rotate X
	rotationmatrix = glm::rotate(rotationmatrix, HullA->GetRotatePoint().y, glm::vec3(0.0f, 1.0f, 0.0f)); // Then rotate Y
	rotationmatrix = glm::rotate(rotationmatrix, HullA->GetRotatePoint().z, glm::vec3(0.0f, 0.0f, 1.0f)); // Then rotate Z
	PointA1 = glm::vec3(glm::vec4(PointA1,1.0f) * rotationmatrix);
	PointA5 = glm::vec3(glm::vec4(PointA5,1.0f) * rotationmatrix);
	//pos
	PointA1 = PointA1 + HullA->GetPositionPoint();
	PointA5 = PointA5 + HullA->GetPositionPoint();
	//box
	//back
	PointA2 = glm::vec3(PointA1.x, PointA5.y, PointA1.z);
	PointA3 = glm::vec3(PointA5.x, PointA5.y, PointA1.z);
	PointA4 = glm::vec3(PointA5.x, PointA1.y, PointA1.z);
	//front
	PointA6 = glm::vec3(PointA1.x, PointA5.y, PointA5.z);
	PointA7 = glm::vec3(PointA1.x, PointA1.y, PointA5.z);
	PointA8 = glm::vec3(PointA5.x, PointA1.y, PointA5.z);
	//generate the other 6 points

	//box 2
	PointB1 = HullB->GetMaxPoint();
	PointB5 = HullB->GetMinPoint();	
	//scale
	PointB1 = PointB1 * HullB->GetScalePoint();
	PointB5 = PointB5 * HullB->GetScalePoint();
	//rotate points B1 and B5 by objectA rotation
	rotationmatrix = glm::mat4(1.0f); // model matrix
	rotationmatrix = glm::rotate(rotationmatrix, HullB->GetRotatePoint().x, glm::vec3(1.0f, 0.0f, 0.0f)); // Then rotate X
	rotationmatrix = glm::rotate(rotationmatrix, HullB->GetRotatePoint().y, glm::vec3(0.0f, 1.0f, 0.0f)); // Then rotate Y
	rotationmatrix = glm::rotate(rotationmatrix, HullB->GetRotatePoint().z, glm::vec3(0.0f, 0.0f, 1.0f)); // Then rotate Z
	PointB1 = glm::vec3(glm::vec4(PointB1, 1.0f) * rotationmatrix);
	PointB5 = glm::vec3(glm::vec4(PointB5, 1.0f) * rotationmatrix);
	//pos
	PointB1 = PointB1 + HullB->GetPositionPoint();
	PointB5 = PointB5 + HullB->GetPositionPoint();
	//box
	//back
	PointB2 = glm::vec3(PointB1.x, PointB5.y, PointB1.z);
	PointB3 = glm::vec3(PointB5.x, PointB5.y, PointB1.z);
	PointB4 = glm::vec3(PointB5.x, PointB1.y, PointB1.z);
	//front
	PointB6 = glm::vec3(PointB1.x, PointB5.y, PointB5.z);
	PointB7 = glm::vec3(PointB1.x, PointB1.y, PointB5.z);
	PointB8 = glm::vec3(PointB5.x, PointB1.y, PointB5.z);

	//check collision

	//box A
	A.push_back(PointA1);
	A.push_back(PointA2);
	A.push_back(PointA3);
	A.push_back(PointA4);
	A.push_back(PointA5);
	A.push_back(PointA6);
	A.push_back(PointA7);
	A.push_back(PointA8);
	//box B
	B.push_back(PointB1);
	B.push_back(PointB2);
	B.push_back(PointB3);
	B.push_back(PointB4);
	B.push_back(PointB5);
	B.push_back(PointB6);
	B.push_back(PointB7);
	B.push_back(PointB8);
	//a max and min
	MaxA = A[0];
	MinA = A[0];
	for (int i = 1; i < A.size(); i++)
	{
		//max a
		if (A[i].x > MaxA.x) { MaxA.x = A[i].x; }
		if (A[i].y > MaxA.y) { MaxA.y = A[i].y; }
		if (A[i].z > MaxA.z) { MaxA.z = A[i].z; }
		//min a
		if (A[i].x < MinA.x) { MinA.x = A[i].x; }
		if (A[i].y < MinA.y) { MinA.y = A[i].y; }
		if (A[i].z < MinA.z) { MinA.z = A[i].z; }
	}
	//b max and min
	MaxB = B[0];
	MinB = B[0];
	for (int i = 1; i < B.size(); i++)
	{
		//max b
		if (B[i].x > MaxB.x) { MaxB.x = B[i].x; }
		if (B[i].y > MaxB.y) { MaxB.y = B[i].y; }
		if (B[i].z > MaxB.z) { MaxB.z = B[i].z; }
		//min b
		if (B[i].x < MinB.x) { MinB.x = B[i].x; }
		if (B[i].y < MinB.y) { MinB.y = B[i].y; }
		if (B[i].z < MinB.z) { MinA.z = B[i].z; }
	}

	if (MaxA.x >= MinB.x && MinA.x <= MaxB.x &&
		MaxA.y >= MinB.y && MinA.y <= MaxB.y &&
		MaxA.z >= MinB.z && MinA.z <= MaxB.z)
	{
		/*cout << "has hit!" << endl;*/
		/*cout << GameScore << endl;*/

		HullA->getBehaviour()->PostCollision(HullB->getParent());
		HullB->getBehaviour()->PostCollision(HullA->getParent());

		return true;
	}
	else
	{
		//cout << "has not hit" << endl;
		return false;
	}


	////FarthestPoint
	//PointP1 = MaxA;
	//PointP2 = MinB;
	//// Minkowski Difference
	//PointP3 = glm::vec3((MaxA.x - MinB.x), (MaxA.y - MinB.y), (MaxA.z - MinB.z));

	//D = -PointP3;
	//PointP4 = D;

	//if (PointP4.x < 0.0f && PointP4.y < 0.0f && PointP4.z < 0.0f)
	//{

	//}
}
#ifndef MODEL_H_
#define MODEL_H_


#include "Components\Components.h"
#include <vector>
#include "Object.h"
#include "Rendering\Texture.h"
#include "Components\Sub-Components\Transform.h"


class Object;

class Model : public Component
{
private:
	//verts
	std::vector<glm::vec3> m_vertices;
	std::vector<glm::vec3> m_vertexNormalTriplets;
	std::vector<glm::vec2> m_vertexTexturePairs;
	GLuint VAO;

public:

	Model(Object * parent) {
		m_ObjectComponent = parent;
	}
	Model(std::string filePath, Object * parent); // load model
	Texture texture; // texture

	std::string m_modelName; // name

	//get
	std::vector<glm::vec3>& GetVertices();
	std::vector<glm::vec3>& GetNormals();
	std::vector<glm::vec2>& GetTextureCoordinates();

	void Render(Shader & shader);


	void Delete(); //destorying
	void Create(); //starting
	void Update(double DeltaTime); //updating
};
#endif

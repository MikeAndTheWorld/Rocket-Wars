#ifndef MODEL_H_
#define MODEL_H_


#include "Components\Components.h"
#include "Rendering\Texture.h"
#include <vector>
#include "Rendering\Shaders.h"

class Component;


class Model : public Component
{
private:
	std::vector<glm::vec3> m_vertices;
	std::vector<glm::vec3> m_vertexNormalTriplets;
	std::vector<glm::vec2> m_vertexTexturePairs;
	GLuint VAO;



public:
	Texture texture;

	std::string m_modelName;
//void Render(Shader & shader);
	std::vector<glm::vec3>& GetVertices();
	std::vector<glm::vec3>& GetNormals();
	std::vector<glm::vec2>& GetTextureCoordinates();

	void Render(Shader & shader);


	void Delete(); //destorying
	void Create(); //starting
	void Update(double DeltaTime); //updating
};
#endif

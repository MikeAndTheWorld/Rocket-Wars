#include "Model.h"

using namespace std;


vector<glm::vec3>& Model::GetVertices()
{
	return m_vertices;
}
vector<glm::vec3>& Model::GetNormals()
{
	return m_vertexNormalTriplets;
}
vector<glm::vec2>& Model::GetTextureCoordinates()
{
	return m_vertexTexturePairs;
}
void Model::Render(Shader & shader)
{

	glActiveTexture(0);
	texture.Bind();

	GLuint mloc = glGetUniformLocation(shader.ID, "tex");
	glUniform1i(mloc, 0);

	glBindVertexArray(this->VAO);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	//glDrawArrays(GL_TRIANGLES, 0, m_vertexTriplets.size()); // could be 6 or not... maybe 6.
	glDrawArrays(GL_TRIANGLES, 0, m_vertices.size() * 3); // could be 6 or not... maybe 6.

	glBindVertexArray(0);
	glDisableVertexAttribArray(0);
}

void Model::Create()
{

	vector<GLfloat> tempVerts;
	tempVerts.reserve(m_vertices.size() * 3);

	vector<GLfloat> tempUV;
	tempVerts.reserve(m_vertexTexturePairs.size() *2);

	vector<GLfloat> tempNorms;
	tempNorms.reserve(m_vertexNormalTriplets.size() * 3);

	for (int i = 0; i < m_vertices.size(); ++i) 
	{
		tempVerts.push_back(m_vertices[i].x);
		tempVerts.push_back(m_vertices[i].y);
		tempVerts.push_back(m_vertices[i].z);

	}

	for (int i = 0; i < m_vertexTexturePairs.size(); ++i) 
	{
		tempUV.push_back(m_vertexTexturePairs[i].x);
		tempUV.push_back(m_vertexTexturePairs[i].y);
	}

	for (int i = 0; i < m_vertexNormalTriplets.size(); ++i)
	{
		tempNorms.push_back(m_vertexNormalTriplets[i].x);
		tempNorms.push_back(m_vertexNormalTriplets[i].y);
		tempNorms.push_back(m_vertexNormalTriplets[i].z);
	}

	GLuint VBO;
	GLuint UVBO;
	GLuint NBO; //normal buffer object
	//vertex array object
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	//generates buffer
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER, tempVerts.size() * sizeof(GLfloat), &tempVerts[0],GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3,GL_FLOAT, GL_FALSE, 0,(GLvoid*)0);

	glGenBuffers(1, &UVBO);
	glBindBuffer(GL_ARRAY_BUFFER, UVBO);
	glBufferData(GL_ARRAY_BUFFER, tempUV.size() * sizeof(GLfloat), &tempUV[0], GL_STATIC_DRAW);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);

	glGenBuffers(1, &NBO);
	glBindBuffer(GL_ARRAY_BUFFER, NBO);
	glBufferData(GL_ARRAY_BUFFER, tempNorms.size() * sizeof(GLfloat), &tempNorms[0], GL_STATIC_DRAW);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);


// stops binding
	glBindBuffer(GL_ARRAY_BUFFER,0);
	glBindVertexArray(0);

}

void Model::Delete() {} //destorying

void Model::Update(double DeltaTime) {} //updating


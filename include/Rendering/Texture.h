#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

#include <glm.hpp>
#include <gtx/transform.hpp>
#include <string>

#include "Object.h"

using std::string;

class Object;

class Texture : public Component
{
private:

	// Holds the ID of the texture object
	GLuint textureID;
	// Texture image dimensions
	//GLuint SizeX, SizeY; // Width and height of loaded image in pixels
	void BmpLoader(std::string filePath);

public:

	Texture(); // texture construtor
	Texture(Object * parent) {
		m_ObjectComponent = parent; //texture component
	}
	Texture(std::string filePath, Object * parent); // filePath and parent
	GLuint GetTexture(); //get texture
	void Create(); //create
	void Delete(); //destorying
	void Render(Shader & shader); //render
	void Update(double DeltaTime); // update

	void Bind(); // bind the texture

};

#endif
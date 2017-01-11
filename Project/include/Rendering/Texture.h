#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

#include <glm.hpp>
#include <gtx/transform.hpp>
#include <string>
using std::string;


class Texture 
{
private:

	// Holds the ID of the texture object
	GLuint textureID;
	// Texture image dimensions
	//GLuint SizeX, SizeY; // Width and height of loaded image in pixels
	void BmpLoader(std::string filePath);

public:

	//					  // Texture Format
	//GLuint Internal_Format; // Format of texture object
	//GLuint Image_Format; // Format of loaded image
	//					 // Texture configuration
	//GLuint Wrap_S; // Wrapping mode on S axis
	//GLuint Wrap_T; // Wrapping mode on T axis
	//GLuint Filter_Min; // Filtering mode if texture pixels < screen pixels
	//GLuint Filter_Max; // Filtering mode if texture pixels > screen pixels

	
	/*Texture(GLuint width, GLuint height, unsigned char* data);*/
	/*void Bind() const;*/

	Texture();
	GLuint GetTexture();
	void Create(std::string filePath);
	//void Delete(); //destorying
	void Render();
	void Update(double DeltaTime);

	void Bind();

	
	
};

#endif
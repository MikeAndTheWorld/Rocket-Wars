#include "Rendering\Texture.h"

////Create a Texture and set some default values.
//Texture::Texture(GLuint TexWidth, GLuint TexHeight, unsigned char* data) : SizeX(0), SizeY(0), Internal_Format(GL_RGBA), Image_Format(GL_BGRA), Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT), Filter_Min(GL_LINEAR), Filter_Max(GL_NEAREST) {
//	glGenTextures(1, &this->TextureID);
//
//	this->SizeX = TexWidth;
//	this->SizeY = TexHeight;
//	// Create Texture
//	glBindTexture(GL_TEXTURE_2D, this->TextureID);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TexWidth, TexHeight, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
//	// Set Texture wrap and filter modes
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->Wrap_S);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->Wrap_T);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->Filter_Min);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->Filter_Max);
//	// Unbind texture
//	glBindTexture(GL_TEXTURE_2D, 0);
//}
//
//void Texture::Bind() const {
//	glBindTexture(GL_TEXTURE_2D, this->TextureID);
//}

void Texture::BmpLoader(std::string filePath)
{
	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
							  // Actual RGB data
	unsigned char * data;

	FILE * file = fopen(filePath.c_str(), "rb");
	if (!file)
	{
		printf("Image could not be opened\n"); 
	}
	
	if (fread(header, 1, 54, file) != 54) 
	{ // If not 54 bytes read : problem
		printf("Not a correct BMP file\n");
	}

	if (header[0] != 'B' || header[1] != 'M') 
	{
		printf("Not a correct BMP file\n");
	}

	// Read ints from the byte array
	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);

	// Some BMP files are misformatted, guess missing information
	if (imageSize == 0)    imageSize = width*height * 3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos == 0)      dataPos = 54; // The BMP header is done that way

										 // Create a buffer
	data = new unsigned char[imageSize];

	// Read the actual data from the file into the buffer
	fread(data, 1, imageSize, file);

	//Everything is in memory now, the file can be closed
	fclose(file);

	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

}

GLuint Texture::GetTexture()
{
	return textureID;
}

void Texture::Bind() {
	glBindTexture(GL_TEXTURE_2D, this->textureID);
}
void Texture::Update(double DeltaTime)
{

}
void Texture::Render()
{
	//glBindTexture(GL_TEXTURE_2D, this->textureID);
}
void Texture::Create(std::string filePath)
{
	BmpLoader(filePath);
}
Texture::Texture()
{
	
}
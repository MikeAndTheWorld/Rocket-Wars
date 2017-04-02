#ifndef SHADERS_H_
#define SHADERS_H_

#include <GL/glew.h>

#include <glm.hpp>
#include <gtx/transform.hpp>

#include <string>
#include <iostream>
#include <map>


class Shader
{
private:
	// Checks if compilation or linking failed and if so, print the error logs
	void checkCompileErrors(GLuint object, std::string type); // check errors
	void Compile(const GLchar *vertexSource, const GLchar *fragmentSource); // sources
public:
	// State
	GLuint ID;
	// Constructor
	Shader() { }
	// Sets the current shader as active
	Shader  &Use();
	// Compiles the shader from given source code
	
	void loadFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile); //load shader path
};

#endif
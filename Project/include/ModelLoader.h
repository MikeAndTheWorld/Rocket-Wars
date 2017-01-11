#ifndef _MODEL_LOADER_H_
#define _MODEL_LOADER_H_

#include <GL\glew.h>

#include <vector>
#include <iostream>

#include <glm.hpp>

#include "Model.h"

class Model;


//ModelLoader derived from https://github.com/opengl-tutorials/ogl/blob/master/common/objloader.cpp
class ModelLoader {


private:
	//std::vector<glm::vec3> vertices;
	//std::vector<glm::vec2> uvs;
	//std::vector<glm::vec3> normals; // Won't be used at the moment.
public:

	ModelLoader() {}

	Model * Load(const char* path);
};

#endif;
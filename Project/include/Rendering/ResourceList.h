//#ifndef RESOURCE_LIST_H
//#define RESOURCE_LIST_H
//
//#include <GL\glew.h>
//#include <GLFW/glfw3.h>
//#include <map>
//#include <iostream>
//#include <vector>
//
//#include "Rendering\Shaders.h"
//#include "Rendering\MeshInput.h"
//#include "Rendering\Texture.h"
//using namespace std;
//
//class ResourceList
//{
//private:
//	
//	static ResourceList * Get_Instance;
//
//	// Private constructor, that is we do not want any actual resource manager objects. Its members and functions should be publicly available (static).
//	ResourceList() { }
//	// Loads and generates a shader from file
//	Shader loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile);
//
//	map<string, Shader> Shader;
//	map<string, MeshInput> MeshInput;
//	map<string, Texture> Texture;
//
//	string m_currentShaderIdentifier_;
//
//public:
//	static ResourceList *getInstance()
//	{
//
//		if (Get_Instance == 0) {
//
//			ResourceList * temp = new ResourceList();
//			Get_Instance = temp;
//
//
//
//		}
//		// Instantiated on first use.
//		return Get_Instance;
//	}
//	// Resource storage
//
//	bool useShader(std::string pId);
//
//	std::string getCurrentShaderID() {
//		return m_currentShaderIdentifier_;
//	}
//
//	Shader LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, std::string name);
//	// Retrieves a stored sader
//	Shader GetShader(std::string name);
//
//	Texture loadTexture(const GLchar *file, GLboolean alpha, std::string name);
//	Texture GetTexture(std::string name);
//
//
//	MeshInput * RegisterMesh(std::string pPath, MeshInput pMesh);
//	MeshInput GetRawMesh(std::string pPath);
//
//	bool checkMeshExists(std::string pPath);
//
//};
//#endif
//

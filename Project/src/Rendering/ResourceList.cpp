//
//#include "Rendering\ResourceList.h"
//#include "Rendering\MeshInput.h"
//
//ResourceList * ResourceList::Get_Instance = 0;
//
//Shader ResourceList::loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile)
//{
//	// 1. Retrieve the vertex/fragment source code from filePath
//	std::string vertexCode;
//	std::string fragmentCode;
//	std::string geometryCode;
//	try
//	{
//		// Open files
//		std::ifstream vertexShaderFile(vShaderFile);
//		std::ifstream fragmentShaderFile(fShaderFile);
//		std::stringstream vShaderStream, fShaderStream;
//		// Read file's buffer contents into streams
//		vShaderStream << vertexShaderFile.rdbuf();
//		fShaderStream << fragmentShaderFile.rdbuf();
//		// close file handlers
//		vertexShaderFile.close();
//		fragmentShaderFile.close();
//		// Convert stream into string
//		vertexCode = vShaderStream.str();
//		fragmentCode = fShaderStream.str();
//	}
//	catch (std::exception e)
//	{
//		std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
//	}
//	const GLchar *vShaderCode = vertexCode.c_str();
//	const GLchar *fShaderCode = fragmentCode.c_str();
//	const GLchar *gShaderCode = geometryCode.c_str();
//	// 2. Now create shader object from source code
//	Shader shader;
//	shader.Compile(vShaderCode, fShaderCode);
//	return shader;
//}
//
//
//Texture ResourceList::loadTexture(const GLchar *filePath, GLboolean alpha, std::string name) {
//	Texture texture;
//	if (alpha)
//	{
//		texture.Internal_Format = GL_RGBA;
//		texture.Image_Format = GL_RGBA;
//	}
//
//
//	// Data read from the header of the BMP file
//	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
//	unsigned int dataPos;     // Position in the file where the actual data begins
//	unsigned int width, height;
//	unsigned int imageSize;   // = width*height*3
//							  // Actual RGB data
//	unsigned char * data;
//
//	// Open the file
//	FILE * file = fopen(filePath, "rb");
//
//	if (!file) { printf("Image could not be opened\n"); }
//
//
//	if (fread(header, 1, 54, file) != 54) { // If not 54 bytes read : problem
//		printf("Not a correct BMP file\n");
//	}
//
//	if (header[0] != 'B' || header[1] != 'M') {
//		printf("Not a correct BMP file\n");
//	}
//
//	// Read ints from the byte array
//	dataPos = *(int*)&(header[0x0A]);
//	imageSize = *(int*)&(header[0x22]);
//	width = *(int*)&(header[0x12]);
//	height = *(int*)&(header[0x16]);
//
//	// Some BMP files are misformatted, guess missing information
//	if (imageSize == 0)    imageSize = width*height * 3; // 3 : one byte for each Red, Green and Blue component
//	if (dataPos == 0)      dataPos = 54; // The BMP header is done that way
//
//										 // Create a buffer
//	data = new unsigned char[imageSize];
//
//	// Read the actual data from the file into the buffer
//	fread(data, 1, imageSize, file);
//
//
//
//
//	// Now generate texture
//	texture = Texture(width, height, data);
//	// And finally free image data
//
//	//Everything is in memory now, the file can be closed
//	fclose(file);
//
//	Textures[name] = texture;
//	return Textures[name];
//}
//
//Texture ResourceList::GetTexture(std::string name)
//{
//	return Textures[name];
//}
//
//bool ResourceList::useShader(std::string pId) {
//
//	//Try to find the shader, and if so, use it, otherwise return false to prevent error.
//	auto iter = Shaders.find(pId);
//	if (iter != Shaders.end())
//	{
//		// key 2 exists, do something with iter->second (the value)
//		iter->second.Use();
//		m_currentShaderIdentifier_ = pId;
//		return true;
//	}
//	return false;
//}
//
//Shader ResourceList::LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, std::string name)
//{
//	Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile);
//	return Shaders[name];
//}
//
//Shader ResourceList::GetShader(std::string name)
//{
//	return Shaders[name];
//}
//
//RawMesh * ResourceList::RegisterMesh(std::string pPath, RawMesh pMesh) {
//	MeshFactory factory;
//
//	Meshes[pPath] = pMesh;
//	//Mesh * meshPointer = &Meshes[pPath];
//
//	return &Meshes[pPath];
//}
//
//RawMesh ResourceList::GetRawMesh(std::string pPath) {
//	return Meshes[pPath];
//}
//
//bool ResourceList::checkMeshExists(std::string pPath) {
//	auto iter = Meshes.find(pPath);
//	if (iter != Meshes.end())
//	{
//
//		if (iter->first == pPath) {
//			return true;
//		}
//	}
//	return false;
//}
//

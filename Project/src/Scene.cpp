#include "Scene.h"


using namespace std;

void Scene::initScene(FpsCamera * m_FpsCamera)
{

	Window::getInstance()->getSize(width, height);
	this->m_FpsCamera = m_FpsCamera;

	Shader shader;
	shader.loadFromFile("./shaders/Vertex.vert", "./shaders/Fragment.frag");
	ShaderList["default"] = shader;

	Texture texture;
	texture.Create("./Texture/test.bmp");

	TextureList["test"] = texture;

	ShaderList.at("default").Use();

	GLuint loc = glGetUniformLocation(ShaderList.at("default").ID, "mProjection");

	glm::mat4 persp = glm::perspective(45.0f, 1920 / 1080.0f, 0.1f, 100.0f);
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(persp));


	setLightParams(m_FpsCamera);

	/*GLuint cLoc = glGetUniformLocation(ShaderList.at("default").ID, "colour");
	glUniform4f(cLoc, 0.0f, 1.0f, 0.0f, 1.0f);*/

	//ModelLoader loader;
	//Model Cube = loader.Load("Models\\cube.obj");
	//Cube.initData();
	///*Model ship = loader.Load("Models//ship1.obj");
	//ship.initData();*/
	//modelList.push_back(Cube);
	/*modelList.push_back(ship);*/
	modelList.push_back(new Object("Models\\cube.obj", TextureList["test"]));
	//modelList.push_back(new Object("Models\\cube2.obj"));

	glfwSetCursorPos(Window::getInstance()->getWindow(), width / 2, height / 2);

}

void Scene::Update(double DeltaTime) {

	//temp delete later
	//update comonents
	m_FpsCamera->Update(&ShaderList.at("default"));

	//glm::mat4 view = glm::lookAt(
	//	glm::vec3(5.0f, 5.0f, 5.0f),
	//	glm::vec3(0.0f, 0.0f, 0.0f),
	//	glm::vec3(0.0f, 1.0f, 0.0f)
	//);

	///set shader uniofmrs
	/*GLuint mloc = glGetUniformLocation(ShaderList.at("default").ID, "mView");
	glUniformMatrix4fv(mloc, 1, GL_FALSE, glm::value_ptr(view));*/
	glfwSetCursorPos(Window::getInstance()->getWindow(), width / 2, height / 2);

	GLuint mloc = glGetUniformLocation(ShaderList.at("default").ID, "mModel");
	glm::mat4 model(1.0f);
	glUniformMatrix4fv(mloc, 1, GL_FALSE, glm::value_ptr(model));

	mloc = glGetUniformLocation(ShaderList.at("default").ID, "NormalMatrix");
	glm::mat3 normMat = glm::transpose(glm::inverse(glm::mat3(model)));
	glUniformMatrix3fv(mloc, 1, GL_FALSE, glm::value_ptr(normMat));
	//prog.setUniform("NormalMatrix", normMat);
}

void Scene::setLightParams(FpsCamera * m_FpsCamera)
{

	glm::vec3 worldLight = glm::vec3(10.0f, 10.0f, 10.0f);

	GLuint loc = glGetUniformLocation(ShaderList.at("default").ID, "LightPosition");
	glUniform3f(loc, worldLight.x, worldLight.y,worldLight.z);

	loc = glGetUniformLocation(ShaderList.at("default").ID, "La");
	glUniform3f(loc, 0.4f, 0.4f, 0.4f);

	loc = glGetUniformLocation(ShaderList.at("default").ID, "Ld");
	glUniform3f(loc, 0.6f, 0.6f, 0.6f);

	loc = glGetUniformLocation(ShaderList.at("default").ID, "Ls");
	glUniform3f(loc, 0.5f, 0.5f, 0.5f);
}

void Scene::Render()
{
	for (int i = modelList.size(); i--;)
	{
		modelList[i]->Render(ShaderList.at("default"));
	}
}

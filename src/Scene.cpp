#include "Scene.h"
#include "XML/XMLreader.h"

using namespace std;

void Scene::initScene()
{
	Window::getInstance()->getSize(width, height);

	Shader shader;
	shader.loadFromFile("./shaders/Vertex.vert", "./shaders/Fragment.frag"); // shader files
	ShaderList["default"] = shader;

	ShaderList.at("default").Use();

	GLuint loc = glGetUniformLocation(ShaderList.at("default").ID, "mProjection");

	glm::mat4 persp = glm::perspective(45.0f, 1920.0f / 1080.0f, 0.1f, 1500.0f);
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(persp));

	setLightParams(/*m_FpsCamera*/);

	ModelLoader loader;

	//objectList.reserve(100);
	XMLreader * load = new XMLreader("./XML/Scene.xml");
	objectList = load->LoadList();
	XMLreader * loadGUI = new XMLreader("./XML/GUI.xml");
	GUIList = loadGUI->LoadList();

	glfwSetCursorPos(Window::getInstance()->getWindow(), width / 2, height / 2); //mouse pos

}

void Scene::Update(double DeltaTime) 
{
	for (int i = 0; i < objectList.size(); ++i) // list of objects
	{
		if (objectList[i]->CheckComponentExists<ConvexHull>())
		{
			ConvexHull * HullA = objectList[i]->getComponent<ConvexHull>(); //1st hull
																			// find all object with convex hull
			for (int j = 0; j < objectList.size(); ++j) //check other hull
			{
				if (objectList[j]->CheckComponentExists<ConvexHull>()) {
					ConvexHull * HullB = objectList[j]->getComponent<ConvexHull>();
					if (i != j)//objectList[j] has convex hull
					{
						if (collision.HasHit(HullA, HullB))
						{
							if (objectList[i]->CheckComponentExists<ShipCollisionActivity>())
							{
								delete objectList[i];
								objectList.erase(objectList.begin() + i);
								i--;
								j = 0;
								break;
							}
							else if (objectList[j]->CheckComponentExists<ShipCollisionActivity>())
							{
								delete objectList[j];
								objectList.erase(objectList.begin() + j);
								End++;
								j--;
								break;
							}
						}

					}
				}
			}

		}
	}
	for (int i = 0; i < objectList.size(); ++i) // list of objects
	{
		objectList[i]->Update(DeltaTime);
		if (objectList[i]->CheckComponentExists<FpsCamera>())
		{
				GLuint loc = glGetUniformLocation(ShaderList.at("default").ID, "mView");
				glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(objectList[i]->getComponent<FpsCamera>()->getView()));
				loc = glGetUniformLocation(ShaderList.at("default").ID, "mProjection");

				glm::mat4 persp = glm::perspective(45.0f, 1920.0f / 1080.0f, 0.1f, 1500.0f);
				glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(persp));
		}
	}
	for (int i = 0; i < GUIList.size(); ++i) // list of objects
	{
		GUIList[i]->Update(DeltaTime);
	}

	glfwSetCursorPos(Window::getInstance()->getWindow(), width / 2, height / 2);

	GLuint mloc = glGetUniformLocation(ShaderList.at("default").ID, "mModel");
	glm::mat4 model(1.0f);
	glUniformMatrix4fv(mloc, 1, GL_FALSE, glm::value_ptr(model));

	mloc = glGetUniformLocation(ShaderList.at("default").ID, "NormalMatrix");
	glm::mat3 normMat = glm::transpose(glm::inverse(glm::mat3(model)));
	glUniformMatrix3fv(mloc, 1, GL_FALSE, glm::value_ptr(normMat));
	//prog.setUniform("NormalMatrix", normMat);
	

}

void Scene::setLightParams()
{
	// lighting
	glm::vec3 worldLight = glm::vec3(500.0f, 500.0f, 500.0f);

	GLuint loc = glGetUniformLocation(ShaderList.at("default").ID, "LightPosition");
	glUniform3f(loc, worldLight.x, worldLight.y,worldLight.z);

	loc = glGetUniformLocation(ShaderList.at("default").ID, "La"); //ambent
	glUniform3f(loc, 0.7f, 0.7f, 0.7f);

	loc = glGetUniformLocation(ShaderList.at("default").ID, "Ld"); //difuse
	glUniform3f(loc, 0.85f, 0.85f, 0.85f);

	loc = glGetUniformLocation(ShaderList.at("default").ID, "Ls"); // spec
	glUniform3f(loc, 0.85f, 0.85f, 0.85f);
}

void Scene::Render()
{
	
	for (int i = objectList.size(); i--;) // list of render
	{
		objectList[i]->Render(ShaderList.at("default"));
	}
	
	for (int i = GUIList.size(); i--;) // list of objects
	{
		GUIList[i]->Render(ShaderList.at("default"));
	}
}
 
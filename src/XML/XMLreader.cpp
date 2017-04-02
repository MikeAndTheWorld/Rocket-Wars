#include"XML\XMLreader.h"

XMLreader::XMLreader(const char* FilePath)
{
	XMLError Error = DocumentLoader.LoadFile(FilePath);
	if (Error != XML_SUCCESS)
	{
		return;
	}
};

std::vector<Object*> XMLreader::LoadList()
{
	//vector of object
	vector<Object*> VectorOfObject;
	VectorOfObject.reserve(100); // reserve
								 //load element
	XMLElement* Root = DocumentLoader.FirstChildElement("Scene");
	//cout << "root: " << Root->Name() << endl;
	XMLElement* GameChild = Root->FirstChildElement("Object");
	//cout << GameChild->Name() << endl;

	while (GameChild != nullptr)
	{
		Object* object = new Object();
		VectorOfObject.push_back(object);
		XMLElement * Component = GameChild->FirstChildElement();
		while (Component != nullptr)
		{
			const char * ComponentName = Component->Name();
			// movement
			if (CompareString(ComponentName, "Movement"))
			{
				Movement * temp = new Movement(object);
				//and also add this component to the object
				object->AddComponentList(temp);
			}
			// Collide movement
			if (CompareString(ComponentName, "CollideMovement"))
			{
				CollideMovement * temp = new CollideMovement(object);
				//and also add this component to the object
				object->AddComponentList(temp);
			}

			if (CompareString(ComponentName, "ConvexHull"))
			{
				ConvexHull * temp = new ConvexHull(object);
				//and also add this component to the object
				object->AddComponentList(temp);
			}
			if (CompareString(ComponentName, "BoxCollisionActivity"))
			{
				BoxCollisionActivity * temp = new BoxCollisionActivity(object);
				//and also add this component to the object
				object->AddComponentList(temp);
				object->getComponent<ConvexHull>()->setBehaviour(object->getComponent<BoxCollisionActivity>());
			}
			if (CompareString(ComponentName, "ShipCollisionActivity"))
			{
				ShipCollisionActivity * temp = new ShipCollisionActivity(object);
				//and also add this component to the object
				object->AddComponentList(temp);
				object->getComponent<ConvexHull>()->setBehaviour(object->getComponent<ShipCollisionActivity>());
			}
			if (CompareString(ComponentName, "BlackHoleCollisionActivity"))
			{
				BlackHoleCollisionActivity * temp = new BlackHoleCollisionActivity(object);
				//and also add this component to the object
				object->AddComponentList(temp);
				object->getComponent<ConvexHull>()->setBehaviour(object->getComponent<BlackHoleCollisionActivity>());
			}
			if (CompareString(ComponentName, "WormHoleCollisionActivity"))
			{
				WormHoleCollisionActivity * temp = new  WormHoleCollisionActivity(object);
				//and also add this component to the object
				object->AddComponentList(temp);
				object->getComponent<ConvexHull>()->setBehaviour(object->getComponent<WormHoleCollisionActivity>());
			}
			if (CompareString(ComponentName, "Aim"))
			{
				Aim * temp = new Aim(object);
				//and also add this component to the object
				object->AddComponentList(temp);
			}
			if (CompareString(ComponentName, "GUI"))
			{
				GUI * temp = new GUI(object);
				//and also add this component to the object
				object->AddComponentList(temp);
			}
			if (CompareString(ComponentName, "Camera"))
			{
				FpsCamera * temp = new FpsCamera(object);
				//and also add this component to the object
				object->AddComponentList(temp);
			}
			if (CompareString(ComponentName, "Animation"))
			{
				Animation * temp = new Animation(object);
				//and also add this component to the object
				object->AddComponentList(temp);
			}
			if (CompareString(ComponentName, "BAR"))
			{
				BAR * temp = new BAR(object);
				//and also add this component to the object
				object->AddComponentList(temp);
			}
			if (CompareString(ComponentName, "Menu"))
			{
				Menu * temp = new Menu(object);
				//and also add this component to the object
				object->AddComponentList(temp);
			}
			//model
			if (CompareString(ComponentName, "Model"))
			{
				XMLElement * CompChild = Component->FirstChildElement();
				while (CompChild != nullptr)
				{
					const char * CompChildName = CompChild->Name();
					if (CompareString(CompChildName, "TexturePath"))
					{
						//add a new texture component because we read
						//in the xml file that it has a transform component
						string TexturePath = CompChild->GetText();
						Texture * temp = new Texture(TexturePath, object);
						//and also add this component to the object
						object->AddComponentList(temp);

					}
					if (CompareString(CompChildName, "ModelPath"))
					{
						//add a new model component
						//in the xml file that it has a transform component
						ModelLoader * temp = new ModelLoader();
						const char * ModelPath = CompChild->GetText();
						Model * tmpModel = temp->Load(ModelPath, object);
						object->AddComponentList(tmpModel);
					}
					CompChild = CompChild->NextSiblingElement();
				}
			}

			// transform
			if (CompareString(ComponentName, "Transform"))
			{
				//create a new transform component because we read
				//in the xml file that it has a transform component
				Transform * temp = new Transform(object);
				//and also add this component to the object
				object->AddComponentList(temp);
				//set default scale in case the scale is not set
				temp->SetScale(glm::vec3(1, 1, 1));

				XMLElement * CompChild = Component->FirstChildElement();
				while (CompChild != nullptr)
				{
					glm::vec3 Position, Scale, Rotation ,TurningPoint;
					const char * CompChildName = CompChild->Name();
					//position
					if (CompareString(CompChildName, "Position"))
					{
						//get the position
						float X = 0.0f;
						float Y = 0.0f;
						float Z = 0.0f;
						XMLElement * ELement = CompChild->FirstChildElement();
						while (ELement != nullptr)
						{
							const char * elemName = ELement->Name();
							if (CompareString(elemName, "X"))
							{
								ELement->QueryFloatText(&X);
							}
							if (CompareString(elemName, "Y"))
							{
								ELement->QueryFloatText(&Y);
							}
							if (CompareString(elemName, "Z"))
							{
								ELement->QueryFloatText(&Z);
							}
							ELement = ELement->NextSiblingElement();
						}
						//set the position
						temp->SetPos(glm::vec3(X, Y, Z));
					}
					//scale
					if (CompareString(CompChildName, "Scale"))
					{
						float X = 0.0f;
						float Y = 0.0f;
						float Z = 0.0f;
						XMLElement * ELement = CompChild->FirstChildElement();
						while (ELement != nullptr)
						{
							const char * elemName = ELement->Name();
							if (CompareString(elemName, "X"))
							{
								ELement->QueryFloatText(&X);
								//std::cout << X << std::endl;
							}
							if (CompareString(elemName, "Y"))
							{
								ELement->QueryFloatText(&Y);
							}
							if (CompareString(elemName, "Z"))
							{
								ELement->QueryFloatText(&Z);
							}
							ELement = ELement->NextSiblingElement();
						}
						//set the position
						temp->SetScale(glm::vec3(X, Y, Z));
					}
					//Rotation
					if (CompareString(CompChildName, "Rotation"))
					{
						float X = 0.0f;
						float Y = 0.0f;
						float Z = 0.0f;
						XMLElement * ELement = CompChild->FirstChildElement();
						while (ELement != nullptr)
						{
							const char * elemName = ELement->Name();
							if (CompareString(elemName, "X"))
							{
								ELement->QueryFloatText(&X);
							}
							if (CompareString(elemName, "Y"))
							{
								ELement->QueryFloatText(&Y);
							}
							if (CompareString(elemName, "Z"))
							{
								ELement->QueryFloatText(&Z);
							}
							ELement = ELement->NextSiblingElement();
						}
						//set the position
						temp->SetRotate(glm::vec3(X, Y, Z));
					}
					//TurningPoint
					if (CompareString(CompChildName, "TurningPoint"))
					{
						float X = 0.0f;
						float Y = 0.0f;
						float Z = 0.0f;
						XMLElement * ELement = CompChild->FirstChildElement();
						while (ELement != nullptr)
						{
							const char * elemName = ELement->Name();
							if (CompareString(elemName, "X"))
							{
								ELement->QueryFloatText(&X);
							}
							if (CompareString(elemName, "Y"))
							{
								ELement->QueryFloatText(&Y);
							}
							if (CompareString(elemName, "Z"))
							{
								ELement->QueryFloatText(&Z);
							}
							ELement = ELement->NextSiblingElement();
						}
						//set the position
						temp->SetTurningPoint(glm::vec3(X, Y, Z));
					}

					CompChild = CompChild->NextSiblingElement();
				}
			}
			Component = Component->NextSiblingElement();
		}
		object->Create(); // create
		GameChild = GameChild->NextSiblingElement("Object");
	}

	return VectorOfObject;
}
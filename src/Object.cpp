#include "Object.h"

Object::Object()
{
	ComponentList.reserve(20);
}
void Object::Create() // create for loop
{
	for (int i = 0; i < ComponentList.size(); i++) {
		ComponentList[i]->Create();
	}
	
}
void Object::Update(double DeltaTime) // update for loop
{
	for (int i = 0; i < ComponentList.size(); i++) {
		ComponentList[i]->Update(DeltaTime);
	}
}
void Object::Render(Shader &shader) // render for loop
{

	for (int i = 0; i < ComponentList.size(); i++) {
		ComponentList[i]->Render(shader);
	}

}
void Object::AddComponentList(Component  * cList) // push back component
{
	ComponentList.push_back(cList);
}

std::vector<Component*> Object::GetComponentList() // get component
{
	return ComponentList;
}

//template<typename T>
//bool Object::CheckComponentExists()
//{
//	if (ComponentList.size() > 0)
//		for (std::vector<Component*>::iterator i = ComponentList.begin(); i != ComponentList.end(); ++i)
//		{
//			if (iter != nullptr)
//			{
//				if (T type = dynamic_cast<T>(i))
//				{
//					return true;
//				}
//			}
//		}
//	return false; 
//}




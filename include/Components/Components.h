#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>

#include "Object.h"

class Object;

class Component
{
private:

protected:
	Object * m_ObjectComponent; //object parent
public:

	std::string m_CompName; //name of the component
	virtual void Delete() = 0; //destorying
	virtual void Create() = 0; //starting
	virtual void Update(double DeltaTime) = 0; //updating
	virtual void Render(Shader & shader) = 0;

	void SetComponent(Object *pComponent) // set the parent
	{
		m_ObjectComponent = pComponent;
	}

	Object *  getParent() {
		return m_ObjectComponent; // object
	}
};
#endif

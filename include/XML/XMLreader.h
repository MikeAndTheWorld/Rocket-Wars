#ifndef XML_READER_H
#define XML_READER_H

#include <tinyxml2.h>
#include <vector>
#include "Object.h"
#include "Components\Sub-Components\Transform.h"
#include "Model.h"
#include "ModelLoader.h"
#include "Rendering\Texture.h"
#include "Components\Sub-Components\ConvexHull.h"
#include "Components\Sub-Components\Movement.h"
#include "Components\Sub-Components\Aim.h"
#include "Components\Sub-Components\GUI.h"
#include "Components\Sub-Components\FpsCamera.h"
#include "Components\Sub-Components\Animation.h"
#include "Components\Sub-Components\BAR.h"
#include "Components\Sub-Components\Menu.h"


using namespace tinyxml2;

class XMLreader
{
private:

	XMLDocument DocumentLoader; // load the doc

	bool CompareString(const char* stringA, const char* stringB) // check strings
	{
		if (strcmp(stringA, stringB) == 0)
		{
			return true; 
		}
		return false;
	}


public:

	XMLreader(const char* FilePath); // file path
	std::vector<Object*> LoadList(); // vector of objects

};
#endif
#ifndef FPS_CAMERA_H
#define FPS_CAMERA_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include <gtx/transform.hpp>

#include "Rendering\Shaders.h"
#include "Components\Components.h"
#include "Components\Sub-Components\Transform.h"

class FpsCamera : public Component
{
private:

	const int REFRESH_RATE = 60; // fps rate 60 fps
	// horizontal angle
	float HorizontalAngle;
	// vertical angle
	float VerticalAngle;
	// Initial Field of View
	float initialFoV; 
	float FpsCameraSpeed; // 3 units / second
	float MouseSpeed; // mouse movement speed

	// camera position and direction
	//camera
	float PX ; // pos x
	float PY ; // pos y
	float PZ ; // pos z
	float VX ; // view x
	float VY ; // view y
	float VZ ; // view z

	int CameraMode = 1; // camera changer
	float Zoom;


	//mouse position
	glm::vec2 MousePos;
	// camera pos and view
	glm::vec3 FpsCameraPos;
	glm::vec3 FpsCameraView;
	glm::vec3 right;
	glm::vec3 up;
	glm::mat4 view;
	GLFWwindow * window;
	Transform * transform;

public:
	FpsCamera() {}
	FpsCamera(Object *pComponent); // parent 
	/*void Update(Shader * shader, Transform * transform);*/
	/*void MoveForward();*/
	void Create(); //starting
	void Delete();
	void Update(double DeltaTime); //updating
	void Render(Shader & shader);
	
	glm::mat4 getView()
	{
		return view;
	}
	glm::vec3 getFpsCameraPos() // getpos
	{
		return FpsCameraPos;
	}

	glm::vec3 getFpsCameraView() //getview
	{
		return FpsCameraView;
	}
};
#endif
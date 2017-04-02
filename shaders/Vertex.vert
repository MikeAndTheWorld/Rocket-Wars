#version 430
layout(location = 0) in vec4 vertPosition;
layout(location = 1) in vec2 inUV;
layout(location = 2) in vec3 vertNormal;

uniform mat4 mModel;        //Matrix to convert to world 
   //coordinate system
uniform mat4 mView;         //Matrix to convert into 
   //camera coordinate system
uniform mat4 mProjection;   //Matrix to convert to 
   //normalised screen 
   //coordinates
   
out vec3 vertPos; //Vertex position in eye coords
out vec3 N; //Transformed normal
out vec3 lightPos; //Light position in eye coords
uniform vec3 LightPosition; // Light position 
uniform mat3 NormalMatrix;


out vec2 UV;

void main()
{
//Colour = vertColour;

   vertPos = vec3(mView * mModel * vertPosition); 
     
   lightPos = vec3(mView * mModel * vec4(LightPosition,1.0f));  

   N = normalize( NormalMatrix * vertNormal);

//Transform from local to world to camera to NDCs
 UV = inUV;
 gl_Position = mProjection * mView * mModel * vertPosition;

}


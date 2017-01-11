#version 430

in vec3 vertPos;
in vec3 N;
in vec3 lightPos;

//uniform vec3 Kd;            // Kd = Diffuse reflectivity
uniform vec3 Ld;            // Ld = Diffuse light intensity

//uniform vec3 Ka;            // Ka = Ambient reflectivity
uniform vec3 La;            // La = Ambient light intensity

//uniform vec3 Ks;            // Ks = Specular reflectivity
uniform vec3 Ls;            // Ls = Specular light intensity


uniform sampler2D tex;

in vec2 UV;

layout( location = 0 ) out vec4 FragColour;

void main() {

	vec4 texCol = texture(tex, UV);

	vec4 Ambient = texCol * vec4(La, 1.0);
	
	//Calculate the light vector
	vec3 L = normalize(lightPos - vertPos);
	vec3 R = clamp(-reflect(L, N), 0.0,1.0);
	vec3 V = normalize(-vertPos);
    
	//calculate Diffuse Light Intensity making sure it is not negative 
	//and is clamped 0 to 1  
	vec4 Id = vec4(Ld,1.0) * clamp(dot(N,L), 0.0,1.0);   

	vec4 Diffuse = texCol * Id;
	vec4 specular = texCol * vec4(Ls,1.0) * clamp(dot(R,V),0.0,1.0);

	FragColour =  Ambient + Diffuse + specular;

//  FragColour = vec4(1.0,1.0,1.0,1.0);
}

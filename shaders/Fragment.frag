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

	//vec4 Ambient = texCol * vec4(La, 1.0);
	
	//Calculate the light vector

	vec3 D = lightPos - vertPos;
	vec3 L = normalize(D);
	vec3 R = -reflect(L, N);
	vec3 V = normalize(-vertPos);
	float Dist = sqrt(D.x*D.x + D.y*D.y + D.z*D.z);
    
	//calculate Diffuse Light Intensity making sure it is not negative 
	//and is clamped 0 to 1  
	vec4 Id = vec4(Ld,1.0) * clamp(dot(N,L), 0.0,1.0);
	Id = clamp(Id, 0.0f, 1.0f);
	vec4 Is = vec4(Ld,1.0) * pow(clamp(dot(R,V),0.0,1.0), 8.5);

	vec4 Ambient = texCol * vec4(La, 1.0);
	vec4 Diffuse = texCol * vec4(1.0f) * Id;
	vec4 specular = texCol * vec4(1.0f) * Is;
	
	// Attenuation = Fatt
	float Fatt = 1.0f / (1.0f + (0.0025f * Dist) + (0.00001f * pow(Dist,1.0f)));
	
	FragColour = vec4(Ambient + (Fatt * (Diffuse + specular)));

}
#include <glsl.h>
// Implements an atmospheric model to generate the skybox textures

attribute vec3 aPosition;

uniform vec3 uSunPosition;
uniform float KrESun;
uniform float KmESun;
uniform float Kr4Pi;
uniform float Km4Pi;

uniform int uCubeFace;
uniform float uPlanetRadius;
uniform float uAtmosphereRadius;

varying vec3 vViewDirection;
varying vec3 vMieColour;
varying vec3 vRayleighColour;

void main() {
	// Calculate the ray from (0.0, 1.0, 0.0) above the planet surface
	vec3 rayDirection;
	
	if (uCubeFace == 0) // Right
		rayDirection = normalize(-aPosition.z, aPosition.y, aPosition.x);
	else if (uCubeFace == 1) // Left
		rayDirection = normalize(aPosition.z, aPosition.y, -aPosition.x);
	else if (uCubeFace == 2) // Up
		rayDirection = normalize(aPosition.x, -aPosition.z, aPosition.y);
	else if (uCubeFace == 3) // Down
		rayDirection = normalize(aPosition.x, aPosition.z, -aPosition.y);
	else if (uCubeFace == 4) // Front
		rayDirection = normalize(aPosition);
	else if (uCubeFace == 5) // Back
		rayDirection = normalize(-aPosition.x, aPosition.y, -aPosition.z);
		
	vec3 rayStart = vec3(0.0, 1.0, 0.0) * (1.0 + uPlanetRadius) / uAtmosphereRadius;
	
	// Check for intersection with planet
	
	
	// Find Atmosphere depth
	// float a = dot(rayDirection, rayDirection);
	float a = 1.0; //Since rayDirection is normalized
	float b = dot(rayDirection, rayStart);
	float c = dot(rayStart, rayStart) - 1.0;
	float discriminant = b * b - c;
	float distance = -b + sqrt(discriminant);
	
	// Initialise sampling ray
	float SampleLength = distance / 20;
	float ScaledLength = SampleLength * uAtmosphereRadius;	
	vec3 SampleRay = rayDirection * ScaledLength;
	vec3 SamplePoint = rayStart + SampleRay;
	
	for (int i = 0; i < 20; i++)
	{
		float SamplePointHeight = length(SamplePoint) - uPlanetRadius;
		
		
		SamplePoint += SampleRay;
	}
	
	// Outputs
	gl_Position = vec4(aPosition, 1.0);
} 
#include <glsl.h>
// Implements an atmospheric model to generate the skybox textures

precision mediump float;

const float g = -0.75;
const float g2 = -0.75 * -0.75;

uniform vec3 uSunPosition;

varying vec3 vViewDirection;
varying vec3 vMieColour;
varying vec3 vRayleighColour;

void main() {
	vec3 light_direction = normalize(uSunPosition);
	vec3 view_direction = normalize(vViewDirection);
	float angle = dot(light_direction, vViewDirection);
	
	float RayleighPhase = 1.0;
	
	float MiePhase = 1.5 * ((1.0 - g2) / (2.0 + g2)) * (1.0 + angle * angle) / pow(1.0 + g2 - 2.0 * angle, 1.5);
	
	vec4 colour = RayleighPhase * vRayleighColour + cMiePhase * vMieColour;
	
	gl_FragColor = colour;
}
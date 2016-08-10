#include <glsl.h>
precision mediump float;

const float PI = 3.14159265358979323846;
const float ambient_color = 0.1;
// A single fixed light position
const vec3 light_position = vec3(1.0, 1.0, 1.0);
varying vec3 vPosition;
varying vec3 vNormal;

varying vec2 vTextureCoords;

uniform sampler2D uTexture;

void main(void) {
	vec3 N = normalize(vNormal);
	vec3 L = normalize(light_position - vPosition);

	vec4 Color = texture2D(uTexture, vTextureCoords);
	float NdotL = dot(N, L);
	NdotL = max(NdotL, 0.0);
	gl_FragColor = vec4(Color.xyz * (ambient_color + NdotL), 1.0);

}
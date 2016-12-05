#include <glsl-300-es.h>
precision mediump float;

const float ambient_color = 0.1;

in vec3 position;
in vec3 normal;

uniform vec3 light_direction;
uniform vec4 uniform_color;

out vec4 fragment_color;

void main() {
	vec3 N = normalize(normal);
	vec3 L = normalize(light_direction);
	float NoL = max(dot(N, L), 0.0);

	fragment_color = vec4(uniform_color.rgb * (ambient_color + NoL), 1.0);
}
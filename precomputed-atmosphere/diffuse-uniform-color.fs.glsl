#include <glsl-300-es.h>
precision mediump float;

const float ambient_color = 0.1;

in vec3 position;
in vec3 normal;

uniform vec3 light_direction;
uniform vec4 uniform_color;

out vec4 fragment_color;

void main() {
	vec3 n = normalize(normal);
	vec3 l = normalize(light_direction);

	float mu_nl = dot(n, l);
	mu_nl = max(mu_nl, 0.0);

	fragment_color = vec4(uniform_color.xyz * (ambient_color + mu_nl), 1.0);
}
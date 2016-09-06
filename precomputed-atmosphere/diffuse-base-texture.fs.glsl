#include <glsl-300-es.h>
precision mediump float;

const float ambient_color = 0.1;

in vec3 position;
in vec3 normal;
in vec2 texture_coords;
in vec3 light_direction;

uniform sampler2D texture_sampler;

out vec4 fragment_color;

void main(void) {
	vec3 n = normalize(normal);
	vec3 l = normalize(light_direction - position);

	vec4 texel_color = texture(texture_sampler, texture_coords);
	float mu_nl = dot(n, l);
	mu_nl = max(mu_nl, 0.0);

	fragment_color = vec4(texel_color.xyz * (ambient_color + mu_nl), 1.0);
}
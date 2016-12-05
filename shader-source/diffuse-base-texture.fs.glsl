#include <glsl-300-es.h>
precision mediump float;

const float ambient_color = 0.1;

in vec3 position;
in vec3 normal;
in vec2 texture_coords;

uniform vec3 light_direction;
uniform sampler2D base_color_texture;

out vec4 fragment_color;

void main(void) {
	vec3 N = normalize(normal);
	vec3 L = normalize(light_direction);
	float NoL = max(dot(N, L), 0.0);

	vec4 base_color = texture(base_color_texture, texture_coords);

	fragment_color = vec4(base_color.rgb * (ambient_color + NoL), 1.0);
}
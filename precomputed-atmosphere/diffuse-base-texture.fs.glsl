#include <glsl.h>
precision mediump float;

const float ambient_color = 0.1;

varying vec3 position;
varying vec3 normal;
varying vec2 texture_coords;
varying vec3 light_direction;

uniform sampler2D texture_sampler;

void main(void) {
	vec3 n = normalize(normal);
	vec3 l = normalize(light_direction - position);

	vec4 texel_color = texture2D(texture_sampler, texture_coords);
	float mu_nl = dot(n, l);
	mu_nl = max(mu_nl, 0.0);
	gl_FragColor = vec4(texel_color.xyz * (ambient_color + mu_nl), 1.0);

}
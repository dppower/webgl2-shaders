#include <glsl-300-es.h>
precision mediump float;

float saturate(in float value) {
	return clamp(value, 0.0, 1.0);
}

const float ambient_strength = 0.1;
const float specular_strength = 0.5;
const vec3 light_color = vec3(1.0, 1.0, 1.0);
const float kPi = 3.14159265;
const float kShininess = 16.0;

in vec3 position;
in vec3 normal;
in vec2 texture_coords;

uniform vec3 light_direction;
uniform sampler2D base_color_texture;

out vec4 fragment_color;

void main() {
	vec3 light_position;
	float light_radius;
	float light_distance = length(light_position - position);
	// float attenuation = 1.0 / (constant + distance * linear_coefficient + distance * distance * quadratic_coefficient)
	float attenuation = pow(saturate(1.0 - pow(light_distance / light_radius, 4.0)), 2.0) / (1.0 + light_distance * light_distance);

	// Ambient
	vec3 ambient = ambient_strength * light_color;
	// Diffuse
	vec3 N = normalize(normal);
	vec3 L = normalize(light_direction);
	float NoL = max(dot(N, L), 0.0);
	vec3 diffuse = NoL * light_color;
	// Specular
	vec3 view = normalize(-position);
	//vec3 reflect_light = reflect(-L, N);
	//float phong = pow(max(dot(view, reflect_light), 0.0), 32);
	const float normalisation_factor = (8.0 + kShininess) / (8.0 * kPi);
	vec3 half = normalize(L + view);
	float phong_blinn = pow(max(dot(view, half), 0.0), kShininess);
	vec3 specular = specular_strength * normalisation_factor * phong_blinn * light_color;

	vec4 base_color = texture(base_color_texture, texture_coords);
	fragment_color = vec4(base_color.rgb * (ambient + diffuse + specular), 1.0);
}
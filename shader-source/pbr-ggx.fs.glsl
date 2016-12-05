#include <glsl-300-es.h>
precision mediump float;

const float PI = 3.1415926536;
const vec3 light_color = vec3(1.0, 1.0, 1.0);
const float ambient_strength = 0.1;

in vec3 position;
in vec3 normal;
in vec2 texture_coords;

uniform sampler2D base_color_texture;
uniform sampler2D metal_rough_texture;
uniform vec3 light_direction;

out vec4 fragment_color;

vec3 diffuse_lambert(vec3 diffuse_color) {
	return diffuse_color / PI;
}

vec3 f_schlick(float NoV, vec3 F0) {
	return F0 + (vec3(1.0) - F0) * pow((1.0 - NoV), 5.0);	
}

// g_ggx = (g_lh * g_vh) / (4 * NoL * NoV)
float g_ggx(float a, float NoL, float NoV) {
	float a_2 = a * a;
	float g_lh = NoL + sqrt(NoL * NoL * (1.0 - a_2) + a_2);
	float g_vh = NoV + sqrt(NoV * NoV * (1.0 - a_2) + a_2);	
	return 0.5 / (g_lh * g_vh);
}

float d_ggx(float a, float NoH) {
	float a_2 = a * a;
	float d = 1.0 + (NoH * NoH * (a_2 - 1.0));
	return a_2 / (PI * d * d);	
}

void main() {
	vec3 normal = normalize(normal);
	vec3 light = normalize(light_direction);
	vec3 view = normalize(-position);
	vec3 half = normalize(light + view);
	
	float NoL = max(0.0, dot(normal, light));
	float NoV = max(0.0, dot(normal, view));
	float NoH = max(0.0, dot(normal, half));
	
	vec4 metal_rough = texture(metal_rough_texture, texture_coords);
	float roughness = metal_rough.r;
	float a = roughness * roughness;
	
	vec3 base_color = texture(base_color_texture, texture_coords).rgb;

	float metallic = metal_rough.g;
	vec3 F0 = (metallic > 0.01) ? base_color : vec3(0.04);
	vec3 fresnel = f_schlick(NoV, F0);
	vec3 k_d = (metallic > 0.01) ? vec3(0.0) : (vec3(1.0) - fresnel);

	
	vec3 diffuse_color = k_d * diffuse_lambert(base_color);

	float D = d_ggx(a, NoH);
	float G = g_ggx(a, NoL, NoV);
	
	vec3 specular_color = D * G * fresnel;
	vec3 final_color = NoL * (diffuse_color + specular_color) * light_color;

	fragment_color = vec4(final_color, 1.0);
}
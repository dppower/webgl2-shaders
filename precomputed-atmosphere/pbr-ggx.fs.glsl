#include <glsl-300-es.h>
precision mediump float;

const float PI = 3.1415926536;
const vec3 light_color = vec3(1.0, 1.0, 1.0);
const float ambient_color = 0.1;

in vec3 position;
in vec3 normal;

uniform vec4 uniform_color;
uniform float roughness;
uniform float metallic;
uniform vec3 light_direction;

out vec4 fragment_color;

vec3 diffuse_lambert(vec3 diffuse_color) {
	return diffuse_color / PI;
}

float f_schlick(float NoV, float F0) {
	return F0 + (1.0 - F0) * pow((1.0 - NoV), 5.0);	
}

// g_ggx = (g_lh * g_vh) / (4 * NoL * NoV)
float g_ggx(float a, float NoL, float NoV) {
	float a_2 = a * a;
	float g_lh = NoL + sqrt(NoL * (NoL - NoL * a_2) + a_2);
	float g_vh = NoV + sqrt(NoV * (NoV - NoV * a_2) + a_2);	
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
	vec3 h = normalize(light + view);
	
	float NoL = max(0.0, dot(normal, light));
	float NoV = max(0.0, dot(normal, view));
	float NoH = max(0.0, dot(normal, h));
	
	float a = roughness * roughness;
	
	float F0 = (metallic > 0.01) ? metallic : 0.04;
	float f = f_schlick(NoV, F0);
	float k_d = (metallic > 0.01) ? 0.0 : (1.0 - f);

	vec3 diffuse_color = k_d * (NoL + ambient_color) * diffuse_lambert(uniform_color.rgb);

	float d = d_ggx(a, NoH);
	float g = g_ggx(a, NoL, NoV);
	
	vec3 specular_color = NoL * d * g * f * light_color;

	fragment_color = vec4(diffuse_color + specular_color, 1.0);
}
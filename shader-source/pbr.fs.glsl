#include <glsl-300-es.h>
precision highp float;

// Constants:
const float PI = 3.1415926536;
const float ambient_strength = 0.1;

uniform vec3 light_color = vec3(1.0, 1.0, 1.0);
uniform vec3 light_direction;

#ifdef USE_IBL
#endif

in vec3 position;
in vec2 uv0;
in vec2 uv1;

uniform vec4 base_color_factor = vec4(1.0, 1.0, 1.0, 1.0);
#ifdef BASE_COLOR_TEXTURE_ACTIVE
uniform sampler2D base_color_texture;
#endif
uniform vec2 metallic_roughness_factors = vec2(1.0, 1.0);
#ifdef METAL_ROUGH_MAP_ACTIVE
uniform sampler2D metal_rough_texture;
#endif

// Normals
#ifdef NORMAL_MAP_ACTIVE
uniform sampler2D normal_map;
uniform float normal_scale;
in mat3 tbn;
#else
in vec3 normal;
#endif

out vec4 final_color;

vec3 get_normal() {
	#ifdef HAS_NORMALMAP
	vec3 n = texture2D(u_NormalSampler, v_UV).rgb;
	return normalize(tbn * ((2.0 * n - 1.0) * vec3(u_NormalScale, u_NormalScale, 1.0)));
	#else
	return normal;
	#endif
}

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

	float metallic = metallic_roughness_factors.x;
	float roughness = metallic_roughness_factors.y;

#ifdef METAL_ROUGH_MAP_ACTIVE
	vec4 metal_rough_sample = texture(metal_rough_texture, uv0);
	metallic = metal_rough_sample.b * metallic;
	roughness = metal_rough_sample.g * roughness;
#endif
	roughness = clamp(roughness, 0.04, 1.0);
	metallic = clamp(metallic, 0.0, 1.0);
	float alpha = roughness * roughness;

#ifdef BASE_COLOR_TEXTURE_ACTIVE
	vec4 base_color = texture2D(base_color_texture, uv0) * base_color_factor;
#else
	vec4 base_color = base_color_factor;
#endif

	vec3 normal = normalize(normal);
	vec3 light = normalize(light_direction);
	vec3 view = normalize(-position);
	vec3 half = normalize(light + view);
	
	float NoL = max(0.0, dot(normal, light));
	float NoV = max(0.0, dot(normal, view));
	float NoH = max(0.0, dot(normal, half));
	
	//vec4 metal_rough = texture(metal_rough_texture, texcoord_0);
	//float roughness = metal_rough.r;
	//float a = roughness * roughness;
	
	//vec3 base_color = texture(base_color_texture, texture_coords).rgb;
	//float metallic = metal_rough.g;

	//vec3 F0 = (metallic > 0.01) ? base_color : vec3(0.04);
	vec3 F0 = mix(vec3(0.04), base_color.rgb, metallic);

	vec3 F = f_schlick(NoV, F0);
	float D = d_ggx(alpha, NoH);
	float G = g_ggx(alpha, NoL, NoV);
	
	//vec3 k_d = (metallic > 0.01) ? vec3(0.0) : (vec3(1.0) - F);
	base_color *= 1.0 - metallic;
	vec3 diffuse_color = (vec3(1.0) - F) * diffuse_lambert(base_color);

	vec3 specular_color = D * G * F;
	vec3 final_color = NoL * (diffuse_color + specular_color) * light_color;

	final_color = vec4(final_color, 1.0);
}
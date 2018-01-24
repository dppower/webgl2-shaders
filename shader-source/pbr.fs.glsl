#include <glsl-300-es.h>
precision highp float;

// Constants:
const float PI = 3.1415926536;

uniform vec3 u_light_color = vec3(1.0);
uniform vec3 u_light_direction = vec3(0.0, 0.0, -1.0);

#ifdef USE_IBL
#endif

in vec3 v_position;
in vec3 v_normal;
#ifdef TEXCOORD_0_ACTIVE
in vec2 v_texcoord_0;
#endif
#ifdef TEXCOORD_1_ACTIVE
in vec2 v_texcoord_1;
#endif
#ifdef COLOR_0_ACTIVE
in vec4 v_color_0;
#endif

uniform vec4 u_base_color_factor = vec4(1.0);
#ifdef BASE_COLOR_TEXTURE_ACTIVE
uniform sampler2D u_base_color_texture;
#endif
uniform vec2 u_metallic_roughness_factors = vec2(1.0);
#ifdef METAL_ROUGH_MAP_ACTIVE
#ifdef OCCLUSION_ACTIVE
uniform float u_occlusion_strength;
#endif
uniform sampler2D u_metal_rough_texture;
#endif

// Normals
#ifdef NORMAL_MAP_ACTIVE
uniform sampler2D u_normal_map;
uniform float u_normal_scale;
in vec4 v_tangent;
#endif

#ifdef EMISSIVE_MAP_ACTIVE
uniform sampler2D u_emissive_texture;
uniform vec3 u_emissive_factor;
#endif

out vec4 final_color;

vec3 get_normal() {
#ifdef NORMAL_MAP_ACTIVE
	vec3 ns = texture(u_normal_map, v_texcoord_0).rgb;
	vec3 n = normalize(v_normal);
	vec3 t = normalize(v_tangent.xyz);
	vec3 b = normalize(cross(n, t) * v_tangent.w);
	mat3 tbn = mat3(t, b, n);
	return normalize(tbn * ((2.0 * ns - 1.0) * vec3(u_normal_scale, u_normal_scale, 1.0)));
#else
	return normalize(v_normal);
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

	float metallic = u_metallic_roughness_factors.x;
	float roughness = u_metallic_roughness_factors.y;

#ifdef METAL_ROUGH_MAP_ACTIVE
	vec4 metal_rough_sample = texture(u_metal_rough_texture, v_texcoord_0);
	metallic = metal_rough_sample.b * metallic;
	roughness = metal_rough_sample.g * roughness;
#endif
	roughness = clamp(roughness, 0.04, 1.0);
	metallic = clamp(metallic, 0.0, 1.0);
	float alpha = roughness * roughness;

#ifdef BASE_COLOR_TEXTURE_ACTIVE
	vec4 base_color = texture(u_base_color_texture, v_texcoord_0) * u_base_color_factor;
#else
#ifdef COLOR_0_ACTIVE
	vec4 base_color = v_color_0;
#else
	vec4 base_color = u_base_color_factor;
#endif
#endif

	vec3 normal = get_normal();
	vec3 light = normalize(u_light_direction);
	vec3 view = normalize(-v_position);
	vec3 half = normalize(light + view);
	
	float NoL = max(0.0, dot(normal, light));
	float NoV = max(0.0, dot(normal, view));
	float NoH = max(0.0, dot(normal, half));

	//vec3 F0 = (metallic > 0.01) ? base_color : vec3(0.04);
	vec3 F0 = mix(vec3(0.04), base_color.rgb, metallic);

	vec3 F = f_schlick(NoV, F0);
	float D = d_ggx(alpha, NoH);
	float G = g_ggx(alpha, NoL, NoV);
	
	//vec3 k_d = (metallic > 0.01) ? vec3(0.0) : (vec3(1.0) - F);
	base_color *= 1.0 - metallic;
	vec3 diffuse_color = (vec3(1.0) - F) * diffuse_lambert(base_color);

	vec3 specular_color = D * G * F;
	vec3 final_color = NoL * (diffuse_color + specular_color) * u_light_color;

	final_color = vec4(final_color, 1.0);
}
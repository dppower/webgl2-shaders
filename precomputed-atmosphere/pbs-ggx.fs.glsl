#include <glsl.h>
precision mediump float;

const float PI = 3.1415926536;

varying vec3 vVertexPosition;
varying vec3 vNormal;
varying vec2 vTextureCoordinates;

uniform sampler2D uBaseTexture;
uniform sampler2D uHighlightTexture;
uniform sampler2D uIrradianceMap;

vec3 BlendMaterial(vec3 k_diffuse, vec3 k_specular, float metallic, vec3 k_base) {
	// Semi-conductors are in the range 0.2 and 0.45, 
	// any values outside the range will be set to 0 for dielectrics and 1 for metals
	float semi_conductor = smoothstep(0.2, 0.45, metallic);
	
	vec3 dielectric = k_diffuse + k_specular;
	vec3 metal = k_specular * k_base;
	return mix(dielectric, metal, semi_conductor);	
}

vec3 Diffuse_Lambert(vec3 diffuse_colour) {
	return diffuse_colour * (1.0 / PI);
}

vec3 F_Schlick(vec3 specular_colour, float LoH, float F0) {
	return F0 + (1 - F0) * pow((1 - LoH), 5);	
}

float G_GGX(float roughness, float NoL, float NoV) {
	float a2 = pow(roughness, 2);
	float g_lh = NoL + sqrt(NoL * (NoL - NoL * a2) + a2);
	float g_vh = NoV + sqrt(NoV * (NoV - NoV * a2) + a2);	
	return 0.5 / (g_lh * g_vh);
}

float G_Schlick(float roughness, float NoL, float NoV) {
	// k = a^2 * sqrt(PI)
	float k = roughness * roughness * 1.7724538509;
	float g_lh = NoL * (1- k) + k;
	float g_vh = NoV * (1- k) + k;
	return 0.5 / (g_lh * g_vh);
}

float D_GGX(float NoH) {
	float a2 = pow(roughness, 2);
	float d = (NoH * a2 - NoH) * NoH + 1;
	return a2 / (PI * d * d);	
}

void main() {
	vec3 normal = normalize(vNormal);
	vec3 light = normalize(light_position - vVertexPosition);
	vec3 view = normalize(-vVertexPosition);
	vec3 half = normalize(light + view);
	
	float NoL = max(0.0, dot(normal, light));
	float NoV = max(0.0, dot(normal, view));
	float VoH = max(0.0, dot(view, half));
	
	vec4 BaseTexture = texture2D(uBaseTexture, vTextureCoordinates);
	float roughness = uHighlightTexture.a;
	float roughness_squared = roughness * roughness;
	
	float metallic = uBaseTexture.a;
	
	float F0 = 0.04;
	if (metallic > 0.01) {
		F0 = metallic;	
	}
	
	vec3 irradiance = textureCube(uIrradianceMap, normal).rgb;
	vec4 diffuse = vec4(BaseTexture.rgb * irradiance, 1.0);
}
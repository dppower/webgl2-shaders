#include <glsl.h>
    
const float PI = 3.14159265358979323846;
const vec3 ambient_color = vec3(0.1, 0.1, 0.1);

// A single fixed light position
const vec3 light_position = vec3(1.0, 1.0, 1.0);
const vec3 light_color = vec3(1.0, 1.0, 1.0);
varying vec3 vVertexPosition;
varying vec3 vNormal;

varying vec2 vTextureCoordinates;

uniform sampler2D uBaseTexture;
uniform sampler2D uHighlightTexture;

void main(void) {
	vec3 normal = normalize(vNormal);
	vec3 light = normalize(light_position - vVertexPosition);
	vec3 view = normalize(-vVertexPosition);
	
	float NdotL = max(0.0, dot(normal, light));
	float NdotV = max(0.0, dot(normal, view));
	
	float OneMinusNdotL2 = 1.0 - NdotL * NdotL;
	float OneMinusNdotV2 = 1.0 - NdotV * NdotV;
	float gamma = sqrt(OneMinusNdotL2 * OneMinusNdotV2);
	
	vec4 BaseTexture = texture2D(uBaseTexture, vTextureCoordinates);
	float roughness = BaseTexture.a;
	float roughness_squared = roughness * roughness;	
	vec2 AB = vec2(1.0, 0.0) + vec2(0.45, -0.5) * (roughness_squared / (roughness_squared + vec2(0.57, 0.09));
	
	vec3 light_plane = normalize(light - NdotL * normal);
	vec3 view_plane = normalize(view - NdotV * normal);
	
	float cos_phi = max(0.0, dot(light_plane, view_plane);
	
	float diffuse = NdotL * (AB.x + AB.y * cos_phi * gamma / max(NdotL, NdotV));
	
	vec3 colour = BaseTexture.xyz;
	
	gl_FragColor = vec4(colour * diffuse, 1.0);

}
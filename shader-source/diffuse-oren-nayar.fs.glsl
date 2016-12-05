#include <glsl-300-es.h>
precision mediump float;

const float ambient_color = 0.1;

in vec3 position;
in vec3 normal;

uniform vec4 uniform_color;
uniform float roughness;
uniform vec3 light_direction;

out vec4 fragment_color;

void main(void) {
	vec3 n = normalize(normal);
	vec3 l = normalize(light_direction);
	vec3 v = normalize(-position);
	
	float mu_nl = max(0.0, dot(n, l));
	float mu_nv = max(0.0, dot(n, v));
	
	float nu_nl = 1.0 - mu_nl * mu_nl;
	float nu_nv = 1.0 - mu_nv * mu_nv;
	float gamma = sqrt(nu_nl * nu_nv);

	float a_2 = roughness * roughness;	
	vec2 oren_nayar = vec2(1.0, 0.0) + vec2(0.45, -0.5) * (a_2 / (a_2 + vec2(0.57, 0.09)));
	
	vec3 light_plane = normalize(l - mu_nl * n);
	vec3 view_plane = normalize(v - mu_nv * n);
	
	// phi = azimuthal angle between light and view planes
	float cos_phi = max(0.0, dot(light_plane, view_plane));
	
	float diffuse = mu_nl * (oren_nayar.x + oren_nayar.y * cos_phi * gamma / max(mu_nl, mu_nv));
	
	fragment_color = vec4(uniform_color.xyz * (diffuse + ambient_color), 1.0);
}
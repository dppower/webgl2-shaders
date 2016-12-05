#include <glsl-300-es.h>
precision mediump float;
precision highp sampler3D;
//uniform samplerCube inscatter_sampler;
//uniform sampler2D transmittance_sampler;

uniform sampler3D inscatter_3d_sampler;

in vec3 view_direction;
uniform float layer;
//in vec2 coordinates;

out vec4 fragment_color;

void main() {
	
	float u = 0.5 * (view_direction.x + 1.0);
	float v = 0.5 * (view_direction.y + 1.0);
	vec3 view = vec3(u, v, layer);

	vec4 inscatter_texel = texture(inscatter_3d_sampler, view);

	fragment_color = vec4(inscatter_texel.xyz, 1.0);
}
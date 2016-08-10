#include <glsl.h>
precision mediump float;

const float GROUND_RADIUS = 6360.0;
const float ATMOSPHERE_LIMIT = 6420.0;

const float PI = 3.141592657;

const float SUN_INTENSITY = 100.0;
const float MU_S = 0.8788171;

uniform samplerCube u_inscatter_sampler;
//uniform sampler2D u_transmittance_sampler;

varying vec3 v_view_direction;

//varying vec2 v_coords;

void main() {
	
	vec3 v = normalize(v_view_direction);

	vec4 inscatter_colour = textureCube(u_inscatter_sampler, v);
	//inscatter_colour *= SUN_INTENSITY;

	//gl_FragColor = vec4(inscatter_colour.xyz, 1.0);
	//vec2 uv_coords = 0.5 * (v_coords + 1.0);

	//vec4 inscatter_colour = texture2D(u_transmittance_sampler, uv_coords);
	//inscatter_colour *= SUN_INTENSITY;

	gl_FragColor = vec4(inscatter_colour.xyz, 1.0);
}
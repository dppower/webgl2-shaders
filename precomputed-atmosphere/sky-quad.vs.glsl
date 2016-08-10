#include <glsl.h>

attribute vec2 a_vertex_position;

//uniform mat4 u_inverse_projection;
//uniform mat4 u_inverse_view;

varying vec3 v_view_direction;

//varying vec2 v_coords;

void main() {
	gl_Position = vec4(a_vertex_position, 1.0, 1.0);

	//vec4 unprojected = u_inverse_projection * vec4(a_vertex_position, 1.0, 0.0);

	//v_view_direction = normalize(mat3(u_inverse_view) * vec3(unprojected));
	v_view_direction = normalize(vec3(a_vertex_position, 1.0));
	//v_coords = a_vertex_position;
}
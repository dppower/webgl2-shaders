#include <glsl.h>

attribute vec2 a_vertex_position;

uniform int u_cube_face;

varying vec3 v_view_direction;

void main() {
	gl_Position = vec4(a_vertex_position, 1.0, 1.0);

	if (u_cube_face == 0) { // positive_x
		v_view_direction = normalize(vec3(1.0, a_vertex_position.y, -a_vertex_position.x));
	}
	else if (u_cube_face == 1) { // negative_x
		v_view_direction = normalize(vec3(-1.0, a_vertex_position.y, a_vertex_position.x));
	}
	else if (u_cube_face == 2) { // positive_y
		v_view_direction = normalize(vec3(a_vertex_position.x, 1.0, -a_vertex_position.y));
	}
	else if (u_cube_face == 3) { // negative_y
		v_view_direction = normalize(vec3(a_vertex_position.x, -1.0, a_vertex_position.y));
	}
	else if (u_cube_face == 4) { // positive_z
		v_view_direction = normalize(vec3(a_vertex_position.x, a_vertex_position.y, 1.0));
	}
	else if (u_cube_face == 5) { // negative_z
		v_view_direction = normalize(vec3(-a_vertex_position.x, a_vertex_position.y, -1.0));
	}
}

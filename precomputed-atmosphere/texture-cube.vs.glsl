#include <glsl-300-es.h>

layout(location = 0) in vec2 vertex_position;

uniform int cube_face;

out vec3 view_direction;

void main() {
	gl_Position = vec4(vertex_position, 0.0, 1.0);

	if (cube_face == 0) { // positive_x
		view_direction = vec3(1.0, vertex_position.y, vertex_position.x);
	}
	else if (cube_face == 1) { // negative_x
		view_direction = vec3(-1.0, vertex_position.y, -vertex_position.x);
	}
	else if (cube_face == 2) { // positive_y
		view_direction = vec3(vertex_position.x, -1.0, -vertex_position.y);
	}
	else if (cube_face == 3) { // negative_y
		view_direction = vec3(vertex_position.x, 1.0, vertex_position.y);
	}
	else if (cube_face == 4) { // positive_z
		view_direction = vec3(-vertex_position.x, vertex_position.y, 1.0);
	}
	else if (cube_face == 5) { // negative_z
		view_direction = vec3(vertex_position.x, vertex_position.y, -1.0);
	}
}

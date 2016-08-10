#include <glsl.h>

attribute vec2 a_vertex_position;

varying vec2 v_coordinates;

void main() {
	gl_Position = vec4(a_vertex_position, 1.0, 1.0);

	v_coordinates = a_vertex_position;
}

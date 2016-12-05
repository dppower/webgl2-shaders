#include <glsl-300-es.h>

layout(location = 0) in vec3 vertex_position;
layout(location = 3) in vec3 vertex_color;

uniform mat4 projection_matrix; // projection * view
uniform mat4 view_matrix; // inverse camera transform * object transform
uniform mat4 transform_matrix; // object transform

out vec4 color;

void main() {

	gl_Position = projection_matrix * vec4(vertex_position, 1.0);
	color = vec4(vertex_color, 1.0);
}
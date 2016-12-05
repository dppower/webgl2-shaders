#include <glsl-300-es.h>

in vec3 vertex_position;

uniform mat4 projection_matrix; // projection * view
uniform mat4 view_matrix; // inverse camera transform * object transform
uniform mat4 transform_matrix; // object transform

void main() {

	gl_Position = projection_matrix * vec4(vertex_position, 1.0);
}
#include <glsl.h>

in vec3 vertex_position;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 transform;

void main() {

	gl_Position = projection * view * transform * vec4(vertex_position, 1.0);
}
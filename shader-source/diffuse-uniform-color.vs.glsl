#include <glsl-300-es.h>

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 vertex_normal;

uniform mat4 projection_matrix; // projection * view * transform
uniform mat4 view_matrix; // inverse camera transform * object transform
uniform mat4 transform_matrix; // object transform
uniform mat4 normal_matrix; // transpose(inverse(view))

out vec3 position;
out vec3 normal;

void main() {
	gl_Position = projection_matrix * vec4(vertex_position, 1.0);

	position = vec3(view_matrix * vec4(vertex_position, 1.0));

	normal = mat3(normal_matrix) * vertex_normal;
}
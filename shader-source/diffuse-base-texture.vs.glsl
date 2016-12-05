#include <glsl-300-es.h>

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 vertex_normal;
layout(location = 2) in vec2 vertex_uv_coords;

uniform mat4 projection_matrix; // projection * view * transform
uniform mat4 view_matrix; // inverse camera transform * object transform
uniform mat4 transform_matrix; // object transform
uniform mat4 normal_matrix; // transpose(inverse(view))

out vec3 normal;
out vec3 position;
out vec2 texture_coords;

void main(void) {
	gl_Position = projection_matrix * vec4(vertex_position, 1.0);

	position = vec3(view_matrix * vec4(vertex_position, 1.0));

	normal = mat3(normal_matrix) * vertex_normal;
	
	texture_coords = vertex_uv_coords;
}
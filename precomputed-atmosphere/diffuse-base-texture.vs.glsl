#include <glsl-300-es.h>

const vec3 light_position = vec3(1.0, 1.0, 1.0);

in vec3 vertex_position;
in vec3 vertex_normal;
in vec2 vertex_texture_coords;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 transform;

out vec3 normal;
out vec3 position;
out vec3 light_direction;

void main(void) {
	vec4 viewspace_position = view * transform * vec4(vertex_position, 1.0);
	gl_Position = projection * view * transform * vec4(vertex_position, 1.0);

	normal = vec3(view * transform * vec4(vertex_normal, 0.0));
	position = vec3(viewspace_position);
	light_direction = vec3(view * transform * vec4(light_position, 0.0));
}
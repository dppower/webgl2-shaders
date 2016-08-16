#include <glsl.h>

const vec3 light_position = vec3(1.0, 1.0, 1.0);

attribute vec3 vertex_position;
attribute vec3 vertex_normal;
attribute vec2 vertex_texture_coords;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 transform;

varying vec3 normal;
varying vec3 position;
varying vec3 light_direction;

void main() {
	vec4 viewspace_position = view * transform * vec4(vertex_position, 1.0);
	gl_Position = projection * viewspace_position;

	normal = vec3(view * transform * vec4(vertex_normal, 0.0));
	position = vec3(viewspace_position);
	light_direction = vec3(view * transform * vec4(light_position, 0.0));
}
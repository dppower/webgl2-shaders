#include <glsl.h>

attribute vec3 a_vertex_position;
attribute vec3 a_vertex_normal;
attribute vec2 a_texture_coords;

uniform mat4 u_view;
uniform mat4 u_projection;
uniform mat4 u_transform;

varying vec2 v_texture_coords;
varying vec3 v_normal;
varying vec3 v_position;

void main() {
	vec4 vertex_position = u_view * u_transform * vec4(a_vertex_position, 1.0);
	gl_Position = u_projection * vertex_position;
	v_texture_coords = a_texture_coords;
	v_normal = vec3(u_view * u_transform * vec4(a_vertex_normal, 0.0));
	v_position = vec3(vertex_position);
}
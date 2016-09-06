#include <glsl-300-es.h>

layout(location = 0) in vec2 vertex_position;

uniform mat4 inverse_projection;
uniform mat4 inverse_view;

out vec3 view_direction;

void main() {
	gl_Position = vec4(vertex_position, 0.0, 1.0);

	//vec4 unprojected = inverse_projection * vec4(vertex_position, -1.0, 1.0);
	//float u = 0.5 * (vertex_position.x + 1.0);
	//float v = 0.5 * (vertex_position.y + 1.0);

	//view_direction = vec3(vertex_position.x, -1.0, -vertex_position.y);
	view_direction = mat3(inverse_view) * vec3(vertex_position, -1.0);
}
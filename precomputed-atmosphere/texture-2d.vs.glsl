#include <glsl-300-es.h>

layout(location = 0) in vec2 vertex_position;

out vec2 coordinates;

void main() {
	gl_Position = vec4(vertex_position, 0.0, 1.0);

	coordinates = vertex_position;
}

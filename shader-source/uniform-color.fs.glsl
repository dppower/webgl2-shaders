#include <glsl-300-es.h>
precision mediump float;

uniform vec4 uniform_color;

out vec4 fragment_color;

void main() {

	fragment_color = uniform_color;
}
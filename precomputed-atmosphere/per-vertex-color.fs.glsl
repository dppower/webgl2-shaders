#include <glsl-300-es.h>
precision mediump float;

in vec4 color;

out vec4 fragment_color;

void main() {

	fragment_color = color;
}
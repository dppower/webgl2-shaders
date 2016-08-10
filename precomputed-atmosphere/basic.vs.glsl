attribute vec3 aVertexPosition;

uniform mat4 uView;
uniform mat4 uProjection;
uniform mat4 uTransform;

void main(void) {
	gl_Position = uProjection * uView * uTransform * vec4(aVertexPosition, 1.0);
}
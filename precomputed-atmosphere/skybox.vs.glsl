#version 100

attribute vec2 aPosition;

uniform mat4 uInverseProjection;
uniform mat4 uInverseView;

varying vec3 vViewDirection;

void main() {
	gl_Position = vec4(aPosition, 0.0, 1.0);
	vec4 unprojected = uInverseProjection * vec4(aPosition, 0.0, 1.0);
	vViewDirection = normalize(mat3(uInverseView) * vec3(unprojected));
}
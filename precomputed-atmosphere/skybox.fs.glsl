#version 100
precision mediump float;

varying vec3 vViewDirection;

uniform samplerCube uSkyboxTexture;

void main() {
	gl_FragColor = textureCube(uSkyboxTexture, vViewDirection);
}
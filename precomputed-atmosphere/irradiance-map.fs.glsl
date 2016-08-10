// This shader takes an environment cubemap as input and generates an irradiance map.

precision mediump float;

const float PI = 3.1415926536;

varying vec3 vViewDirection;

uniform samplerCube uEnvironmentMap;
uniform int uCubeFace;

void main() {

	vec3 view = vec3(0,0,0);
	
	if (uCubeFace == 0) // Right
		view = normalize(-vViewDirection.z, vViewDirection.y, vViewDirection.x);
	else if (uCubeFace == 1) // Left
		view = normalize(vViewDirection.z, vViewDirection.y, -vViewDirection.x);
	else if (uCubeFace == 2) // Up
		view = normalize(vViewDirection.x, -vViewDirection.z, vViewDirection.y);
	else if (uCubeFace == 3) // Down
		view = normalize(vViewDirection.x, vViewDirection.z, -vViewDirection.y);
	else if (uCubeFace == 4) // Front
		view = normalize(vViewDirection);
	else if (uCubeFace == 5) // Back
		view = normalize(-vViewDirection.x, vViewDirection.y, -vViewDirection.z);
	
	vec3 up = vec3(0,1,0);
	vec3 right = normalize(cross(up, view));
	up = cross(view, right);
	
	vec3 sumColours = vec3(0,0,0);
	int sampleCount = 0;
	
	for (float phi = 0; phi < 6.283; phi += 0.025) {
		for(float theta = 0; theta < 1.571; theta += 0.1) {			
			vec3 sampleVector = cos(theta) * view + sin(theta) * (cos(phi) * right + sin(phi) * up);
			sumColours += textureCube(uEnvironmentMap, sampleVector).rgb * cos(theta) * sin(theta);
			sampleCount ++;
		}
	}
	vec3 averagedColour = sumColours / sampleCount;
	gl_FragColor = vec4(averagedColour * P1, 1);
}

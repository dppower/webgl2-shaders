#include <glsl-300-es.h>
precision mediump float;

// This shader takes an environment cubemap as input and generates an irradiance map.

const float PI = 3.1415926536;

in vec3 view_direction;

uniform samplerCube radiance;

out vec4 fragment_color;

void main() {

	vec3 view = normalize(view_direction);
	
	vec3 up = vec3(0.0, 1.0, 0.0);
	vec3 right = normalize(cross(up, view));
	up = cross(view, right);
	
	vec3 sum_colors = vec3(0.0, 0.0, 0.0);
	int sample_count = 0;
	
	for (float phi = 0; phi < 6.283; phi += 0.025) {
		for(float theta = 0; theta < 1.571; theta += 0.1) {			
			vec3 sample_vector = cos(theta) * view + sin(theta) * (cos(phi) * right + sin(phi) * up);
			sum_colors += texture(radiance, sample_vector).rgb * cos(theta) * sin(theta);
			sample_count ++;
		}
	}
	vec3 averaged_color = PI * sum_colors / sample_count;
	fragment_color = vec4(averaged_color, 1.0);
}

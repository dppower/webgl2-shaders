#include <glsl-300-es.h>

layout(location = 0) in vec3 POSITION;
layout(location = 1) in vec3 NORMAL;
layout(location = 2) in vec3 TANGENT;
#ifdef TEXCOORD_0_ACTIVE
layout(location = 3) in vec2 TEXCOORD_0;
#endif
#ifdef TEXCOORD_1_ACTIVE
layout(location = 4) in vec2 TEXCOORD_1;
#endif

uniform mat4 projection_matrix; // projection * view * transform
uniform mat4 view_matrix; // inverse camera transform * object transform
//uniform mat4 transform_matrix; // object transform
uniform mat4 normal_matrix; // transpose(inverse(view))

out vec3 normal;
out vec3 position;
out vec2 uv0;
out vec2 uv1;

void main(void) {
	
	position = vec3(view_matrix * vec4(POSITION, 1.0));

	normal = mat3(normal_matrix) * NORMAL;
	
	#ifdef TEXCOORD_0_ACTIVE
	uv0 = TEXCOORD_0;
	#else 
	uv0 = vec2(0.0, 0.0);
	#endif
	#ifdef TEXCOORD_1_ACTIVE
	uv1 = TEXCOORD_1;
	#else 
	uv0 = vec2(0.0, 0.0);
	#endif

	gl_Position = projection_matrix * vec4(POSITION, 1.0);
}
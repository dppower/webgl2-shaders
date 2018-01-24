#include <glsl-300-es.h>

layout(location = 0) in vec3 POSITION;
out vec3 v_position;

layout(location = 1) in vec3 NORMAL;
out vec3 v_normal;

layout(location = 2) in vec4 TANGENT;
#ifdef NORMAL_MAP_ACTIVE
out vec4 v_tangent;
#endif

#ifdef TEXCOORD_0_ACTIVE
layout(location = 3) in vec2 TEXCOORD_0;
out vec2 v_texcoord_0;
#endif

#ifdef TEXCOORD_1_ACTIVE
layout(location = 4) in vec2 TEXCOORD_1;
out vec2 v_texcoord_1;
#endif

#ifdef COLOR_0_ACTIVE
layout(location = 5) in vec4 COLOR_0;
out vec4 v_color_0;
#endif

uniform mat4 u_projection_matrix; // projection * view * transform
uniform mat4 u_view_matrix; // inverse camera transform * object transform
uniform mat3 u_normal_matrix; // transpose(inverse(view))

void main(void) {
	
	v_position = vec3(u_view_matrix * vec4(POSITION, 1.0));

	v_normal = normalize(u_normal_matrix * NORMAL);

#ifdef NORMAL_MAP_ACTIVE
	vec3 tangent = normalize(u_normal_matrix * TANGENT.xyz);
	v_tangent = vec4(tangent, TANGENT.w);
#endif
	
#ifdef TEXCOORD_0_ACTIVE
	v_texcoord_0 = TEXCOORD_0;
#endif

#ifdef TEXCOORD_1_ACTIVE
	v_texcoord_1 = TEXCOORD_1;
#endif

#ifdef COLOR_0_ACTIVE
	v_color_0 = COLOR_0;
#endif

	gl_Position = u_projection_matrix * vec4(POSITION, 1.0);
}
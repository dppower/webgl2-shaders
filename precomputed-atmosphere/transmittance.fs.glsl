#include <glsl-300-es.h>
precision mediump float;
// To precalculate the transmittance term for atmospheric model for the inscattered light.

const float GROUND_RADIUS = 6360.0;
const float ATMOSPHERE_LIMIT = 6420.0;

// Extinction coefficient for Rayleigh = Scattering coefficient.
const vec3 BETA_R = vec3(5.8e-3, 1.35e-2, 3.31e-2);
const float HR = 8.0;

// Extinction coefficient for Mie = scattering + absorption.
const float BETA_M_SCATTER = 4e-3;
const float BETA_M_EX = BETA_M_SCATTER / 0.9;
const float HM = 1.2;

const int TRANSMITTANCE_SAMPLES = 500;

in vec2 coordinates;

out vec4 fragment_color;

// distance to intersection with upper atmosphere boundary
float view_distance(float mu, float r) {
	return -r * mu + sqrt(r * r * (mu * mu - 1.0) + ATMOSPHERE_LIMIT * ATMOSPHERE_LIMIT);  
}

float optical_depth(float H, float r_p, float mu_x) {
    float result = 0.0;	
	float d_i = view_distance(mu_x, r_p) / float(TRANSMITTANCE_SAMPLES);
	float depth_i = exp(-(r_p - GROUND_RADIUS) / H);
	// numerical integration, trapezoidal rule
    for (int i = 1; i <= TRANSMITTANCE_SAMPLES; ++i) {
        float d_q = float(i) * d_i;
		float h_q = sqrt(r_p * r_p + d_q * d_q + 2.0 * d_q * r_p * mu_x) - GROUND_RADIUS;
        float depth_j = exp(-h_q / H);
        result += d_i * (depth_i + depth_j) / 2.0;

        depth_i = depth_j;
    }
    return result;
}

void main() {
	// r_p = radius to point p, in range [GROUND_RADIUS, ATMOSPHERE_LIMIT]
	float r_p = GROUND_RADIUS + ((1.0 + coordinates.x) * 0.5) * (ATMOSPHERE_LIMIT - GROUND_RADIUS);
	// mu_x is in the range [1, mu_h], mu_h is cosine of angle between p and h (tangent point to ground, horizon).
	float mu_x = 1.0 - 0.5 * (coordinates.y + 1.0) * (sqrt(1.0 - pow((GROUND_RADIUS / r_p), 2.0)));
	
	vec3 depth = BETA_R * optical_depth(HR, r_p, mu_x) + BETA_M_EX * optical_depth(HM, r_p, mu_x);
	fragment_color = vec4(exp(-depth), 1.0);
}
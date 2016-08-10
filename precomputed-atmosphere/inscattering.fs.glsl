#include <glsl.h>
precision mediump float;
// Calculate the inscattering table, S, for single scattering

// At latitude 52.0, muS = cos((52.0 - 23.5) * PI / 180) at solar noon;
const float MU_S = 0.8788171;

const float GROUND_RADIUS = 6360.0;
const float ATMOSPHERE_LIMIT = 6420.0;

const vec3 BETA_R = vec3(5.8e-3, 1.35e-2, 3.31e-2);
const float HR = 8.0;

const float BETA_M_SCATTER = 4e-3;
const float HM = 1.2;

const float PI = 3.141592657;
const float PHASE_FRACTION = 3.0 / (16.0 * PI);
const float HALF_PHASE_FRACTION = 0.5 * PHASE_FRACTION;
const float MIE_G = 0.8;

const int INSCATTER_SAMPLES = 500;

uniform sampler2D u_transmittance_sampler;

varying vec3 v_view_direction;

// Distance to intersection with upper atmosphere boundary given a radius and cosine of angle between unit view vector v, and unit position vector u.
float view_distance(float mu, float r) {
    return -r * mu + sqrt(r * r * (mu * mu - 1.0) + ATMOSPHERE_LIMIT * ATMOSPHERE_LIMIT);
}

// Transmittance from point x, intersection point with atmosphere, to point p.
vec4 transmittance(float mu, float r) {
	// Map radius to the range (0, 1), likewise mu.
	float x = (r - GROUND_RADIUS) / (ATMOSPHERE_LIMIT - GROUND_RADIUS);
	float y = 0.5 * (1.0 + mu);
	return texture2D(u_transmittance_sampler, vec2(x, y));
}

// Transmittance from point q, on line px, to point p.
vec4 transmittance_q(float mu_x, vec3 p, vec3 v, vec3 n_q, float r_q) {
	// Get transmittance from x to p.
	float r_p = length(p);
	vec4 t_x = transmittance(mu_x, r_p);
	// Get transmittance from x to q.
	float mu_q = dot(v, n_q);
	vec4 t_xq = transmittance(mu_q, r_q);

	// Return transmittance from q to p.
	vec4 t_q = t_x / t_xq;
	return t_q;
}

// Rayleigh phase function
float phase_rayleigh(float mu) {
	return PHASE_FRACTION * (1.0 + mu * mu);
}

// Mie phase function
float phase_mie(float mu) {
	return (HALF_PHASE_FRACTION * (1.0 - MIE_G * MIE_G) * (1.0 + mu * mu)) / ((2.0 + MIE_G * MIE_G) * pow(1.0 + (MIE_G * MIE_G) - 2.0 * MIE_G * mu, 1.5));
}

vec4 integrand(float mu_x, vec3 p, vec3 v, vec3 s, float d_q) {
	// Radial vector to point q on line px
	vec3 q = (d_q * v) + p;
	// Height of point q above ground.
	float r_q = length(q);
	float h_q = r_q - GROUND_RADIUS;
	// Cosine of angle between s and q.
	vec3 n_q = normalize(q);
	float mu_sq = dot(s, n_q);
	
	// Transmittance of light along s and then along x from point q to p
    vec4 t_sp = transmittance_q(mu_x, p, v, n_q, r_q) * transmittance(mu_sq, r_q);
	vec3 rayleigh = phase_rayleigh(mu_x) * BETA_R * exp(-h_q / HR);
	float mie = phase_mie(mu_x) * BETA_M_SCATTER * exp(-h_q / HM);
	return vec4(t_sp.xyz * (rayleigh + mie), 1.0);
}

vec4 inscatter(vec3 p, vec3 v, vec3 s) {   
	vec4 colour;
	vec3 n_p = normalize(p);
	float mu_x = dot(n_p, v);
	float r_p = length(p);
	float d_i = view_distance(mu_x, r_p) / float(INSCATTER_SAMPLES);
	
	// Check if mu_x is less than mu_h, and return ground colour instead
	float mu_h = -1.0 * sqrt(1.0 - pow((GROUND_RADIUS / r_p), 2.0));
	if (mu_x < mu_h) {
		return vec4(0.5, 0.66, 0.33, 1.0);
	}

	vec4 colour_i = integrand(mu_x, p, v, s, 0.0);
	for (int i = 1; i <= INSCATTER_SAMPLES; ++i) {
        float d_q = float(i) * d_i;
		vec4 colour_j = integrand(mu_x, p, v, s, d_q);
		colour += d_i * (colour_i + colour_j) / 2.0;

		colour_i = colour_j;
	}
	return colour;
}

void main() {
	vec3 v = normalize(v_view_direction);
	vec3 p = vec3(0.0, GROUND_RADIUS + 0.002, 0.0);
	vec3 s = vec3(0.0, MU_S, sqrt(1.0 - MU_S * MU_S));

    vec4 inscatter_colour = inscatter(p, v, s);

    gl_FragColor = inscatter_colour;
}
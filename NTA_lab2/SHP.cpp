#include "header.hpp"

// Китайся теорема
uint64_t crt(vector<pair<uint64_t, uint64_t>>& congruences, uint64_t n) {
	uint64_t x = 0;

	for (size_t i = 0; i < congruences.size(); ++i) {
		uint64_t a = congruences[i].first;
		uint64_t ni = congruences[i].second;

		uint64_t Mi = n / ni;

		uint64_t Ni = mod_inverse(Mi % ni, ni);

		uint64_t term = mul_mod(a, mul_mod(Mi, Ni, n), n);
		x = (x + term) % n;
	}
}
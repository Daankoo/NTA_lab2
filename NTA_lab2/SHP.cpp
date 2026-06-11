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
	return x;
}	



uint64_t solve_for_prime(uint64_t a, uint64_t b, uint64_t p, uint64_t n, uint64_t prime, int exp) {
	// Будуємо таблицю: table[j] = alpha^(n*j/prime) mod p
	vector<uint64_t> table(prime);
	uint64_t base = mod_step(a, n / prime, p);
	table[0] = 1;
	for (uint64_t j = 1; j < prime; ++j)
		table[j] = mul_mod(table[j - 1], base, p);

	uint64_t yi = 0;
	uint64_t a_inv = mod_inverse(a, p);
	uint64_t gamma = 1;
	uint64_t pk = 1;

	for (int k = 0; k < exp; ++k) {
		pk = (k == 0) ? 1 : pk * prime;

		// Ліва частина: (beta * gamma)^(n / prime^(k+1)) mod p
		uint64_t lhs = mul_mod(b, gamma, p);
		lhs = mod_step(lhs, n / (pk * prime), p);

		// Шукаємо xk у таблиці
		uint64_t xk = 0;
		for (uint64_t j = 0; j < prime; ++j) {
			if (table[j] == lhs) {
				xk = j;
				break;
			}
		}

		yi += xk * pk;

		// Оновлюємо gamma = alpha^(-yi) mod p
		uint64_t inv_pk = mod_step(a_inv, pk * xk, p);
		gamma = mul_mod(gamma, inv_pk, p);
	}

	return yi;
}
#include "header.hpp"

// Повний перебір: знаходить x таке що a^x ≡ b (mod p)
// Повертає x, або -1 якщо не знайдено за відведений час
int64_t brute_force(uint64_t a, uint64_t b, uint64_t p) {
	auto start = chrono::high_resolution_clock::now();
	auto limit = chrono::minutes(5);

	uint64_t current = 1;

	for (uint64_t x = 0; x <= p - 2; ++x) {
		if (current == b)
			return x;

		current = mul_mod(current, a, p);

		// Перевірка часу кожні 1000 ітерацій
		if (x % 1000 == 0) {
			auto now = chrono::high_resolution_clock::now();
			if (now - start >= limit)
				return -1;
		}
	}

	return -1;
}
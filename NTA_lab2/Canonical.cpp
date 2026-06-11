#include "header.hpp"

uint64_t gcd(uint64_t a, uint64_t b) {
	while (b != 0) { // a = q*b + r
		uint64_t q = a / b;
		uint64_t r = a % b;

		a = b;
		b = r;
	}

	return a;
}

int64_t gcd_uv(int64_t a, int64_t b, int64_t& u, int64_t& v) {
	int64_t u0 = 1, u1 = 0;
	int64_t v0 = 0, v1 = 1;
	while (b != 0) {
		int64_t q = a / b;
		int64_t r = a % b;
		a = b;
		b = r;
		int64_t u_n = u0 - q * u1;
		int64_t v_n = v0 - q * v1;
		u0 = u1; u1 = u_n;
		v0 = v1; v1 = v_n;
	}
	u = u0;
	v = v0;
	return a;
}

uint64_t mod_inverse(uint64_t a, uint64_t n) {
	int64_t u, v;
	int64_t g = gcd_uv((int64_t)a, (int64_t)n, u, v);
	if (g != 1) return 0; // оберненого не існує
	return (uint64_t)((u % (int64_t)n + (int64_t)n) % (int64_t)n);
}

uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t n) {
	uint64_t result = 0;
	a %= n;

	while (b > 0) {
		if (b % 2 == 1)
			result = (result + a) % n;

		a = (a + a) % n;
		b /= 2;
	}

	return result;
}

uint64_t mod_step(uint64_t a, uint64_t b, uint64_t n) {

	uint64_t c = 1;
	a %= n;

	while (b > 0) {
		if (b % 2 == 1) {
			c = mul_mod(c, a, n);
		}
		a = mul_mod(a, a, n);
		b /= 2;
	}
	return c;
}

void step2(uint64_t p, uint64_t& d, uint64_t& s) {
	d = 1;
	s = 0;
	uint64_t p_1 = p - 1;

	while (p_1 % 2 == 0) {
		p_1 /= 2;
		s += 1;
	}

	d = p_1;
}

bool TestSPP(uint64_t p, uint64_t a, uint64_t d, uint64_t s) {
	uint64_t a_mod = mod_step(a, d, p);

	if (a_mod == 1 || a_mod == p - 1) {
		return 1;
	}

	for (uint64_t r = 0; r < s - 1; ++r) {

		a_mod = mul_mod(a_mod, a_mod, p);

		if (a_mod == p - 1) {
			return 1;
		}
		if (a_mod == 1) {
			return 0;
		}
	}

	return 0;
}

bool MillerRabin(uint64_t p, int k) {
	if (p < 2)
		return 0;

	if (p == 2 || p == 3)
		return 1;

	if (p % 2 == 0)
		return 0;

	uint64_t d, s;

	step2(p, d, s);

	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<uint64_t> dis(2, p - 2);

	for (int i = 0; i < k; ++i) {
		uint64_t x = dis(gen);

		if (gcd(x, p) > 1) {
			return 0;
		}

		if (!TestSPP(p, x, d, s)) {
			return 0;
		}
	}

	return 1;
}

// Метод пробних ділень
uint64_t TrialDivision(uint64_t n) {
	const int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
	for (int p : primes) {
		if (n % p == 0) {
			return p;
		}
	}
	return 1;
}

// р-метод Полларда (модифікація Флойда)
uint64_t PollardRho(uint64_t n) {
	uint64_t x0 = 2;

	while (x0 < n) {
		uint64_t x = x0;
		uint64_t y = x0;
		uint64_t d = 1;

		while (d == 1) {
			x = (mul_mod(x, x, n) + 1) % n;
			y = (mul_mod(y, y, n) + 1) % n;
			y = (mul_mod(y, y, n) + 1) % n;

			uint64_t diff = x > y ? x - y : y - x;
			d = gcd(diff, n);
		}

		if (d != n) {
			return d;
		}

		x0++;
	}

	return 0;
}

void Factorize(uint64_t n, vector<uint64_t>& result) {
	if (n <= 1) return;

	// Просте число — кладемо в результат
	if (MillerRabin(n, 20)) {
		result.push_back(n);
		return;
	}

	// Пробні ділення
	uint64_t d = TrialDivision(n);
	if (d != 1) {
		result.push_back(d);
		Factorize(n / d, result);
		return;
	}

	// р-метод Полларда
	d = PollardRho(n);
	if (d != 0) {
		Factorize(d, result);
		Factorize(n / d, result);
		return;
	}

	cout << "Cannot find canonical decomposition :(" << endl;
}

map<uint64_t, int> canonical_decomposition(uint64_t n) {
	vector<uint64_t> factors;
	Factorize(n, factors);

	map<uint64_t, int> canonical;
	for (auto p : factors) canonical[p]++;
	return canonical;
}
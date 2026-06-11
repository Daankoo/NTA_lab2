#include "header.hpp"

int main(int argc, char* argv[]) {
	uint64_t a, b, p;

	if (argc == 4) {
		a = stoull(argv[1]);
		b = stoull(argv[2]);
		p = stoull(argv[3]);
	}
	else {
		cout << "Solving: a^x = b (mod p)" << endl;
		cout << "Enter a: "; cin >> a;
		cout << "Enter b: "; cin >> b;
		cout << "Enter p: "; cin >> p;
	}

	cout << "\nSPH:         " << sph(a, b, p) << endl;
	cout << "Brute force: " << brute_force(a, b, p) << endl;

	return 0;
}
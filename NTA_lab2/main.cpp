#include "header.hpp"

int main(int argc, char* argv[]) {
	if (argc != 4) {
		cout << "Usage: " << argv[0] << " <a> <b> <p>" << endl;
		cout << "Solves: a^x = b (mod p)" << endl;
		return 1;
	}

	uint64_t a = stoull(argv[1]);
	uint64_t b = stoull(argv[2]);
	uint64_t p = stoull(argv[3]);

	cout << "SPH:        " << sph(a, b, p) << endl;
	cout << "Brute force: " << brute_force(a, b, p) << endl;

	return 0;
}
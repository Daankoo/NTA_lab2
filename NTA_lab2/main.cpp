/*
 Оновити після змін :
 docker build -t daankooo/nta_lab2 .

 Запушити:                    
 docker push daankooo/nta_lab2
 
 Запуск halper:               
 docker run -it oyakymchuk/nta_cp2_helper
 
 Зразу значення:              
 docker run daankooo/nta_lab2 <a> <b> <p>
 
 Поступово:                   
 docker run - it daankooo/nta_lab2
*/ 

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

	cout << endl;

	auto t1 = high_resolution_clock::now();
	uint64_t x_sph = sph(a, b, p);
	auto t2 = high_resolution_clock::now();
	long long us_sph = duration_cast<milliseconds>(t2 - t1).count();
	cout << "SPH:         " << x_sph << " | Time: " << us_sph << " us" << endl;

	auto t3 = high_resolution_clock::now();
	int64_t x_bf = brute_force(a, b, p);
	auto t4 = high_resolution_clock::now();
	long long us_bf = duration_cast<milliseconds>(t4 - t3).count();

	if (x_bf == -1)
		cout << "Brute force: timeout | Time: " << us_bf << " us" << endl;
	else
		cout << "Brute force: " << x_bf << " | Time: " << us_bf << " us" << endl;

	return 0;
}

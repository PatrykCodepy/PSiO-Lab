#include <iostream>

uint64_t factorial(int x) {
	uint64_t tmp = 1;
	for (int index = 1; x >= index; index++) {
		tmp *= index;
	}
	return tmp;
}

int main() {
	uint64_t result = factorial(15);
	std::cout << result << std::endl; // wynik: 1307674368000
	return 1;
}
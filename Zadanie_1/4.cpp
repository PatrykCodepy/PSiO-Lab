#include <iostream>

uint64_t factorial_r(int x) {
	if (x == 0) return 1;
	return factorial_r(x - 1) * x;
}

int main() {
	uint64_t result = factorial_r(15);
	std::cout << result << std::endl;
	return 1;
}
#include <iostream>

void gcd(std::size_t a, std::size_t b) {
	std::size_t c;
	while (b != 0){
		c = a % b;
		a = b;
		b = c;
	}
	std::cout << "Wynik to: " << a;
}

int main() {
	std::size_t a, b;

	std::cout << "Podaj a: ";
	std::cin >> a;
	std::cout << "Podaj b: ";
	std::cin >> b;

	gcd(a, b);
	return 1;
}
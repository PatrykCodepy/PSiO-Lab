#include <random>
#include <iostream>
#include <ctime>
#include <list>
#include <algorithm>

int randomInt(int min, int max) {
	static std::default_random_engine e{ static_cast<long unsigned int>(time(0)) };
	std::uniform_int_distribution<int> d{ min, max };
	return d(e);
}

void print_iterator(std::list<int>& l) {

	for (auto it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << std::endl;
	}
}


void remove_vec(std::list<int>& l) {
	int x;
	std::cout << "Podaj liczbe: " << std::endl;
	std::cin >> x;

	for (auto it = l.begin(); it != l.end(); ++it) {
		if (*it == x) { it = l.erase(it); }
	}

}

int main() {
	size_t N = 40;
	std::list<int> lis;

	for (size_t i = 0; i < N; ++i) {
		lis.push_back(randomInt(-20, 20));
	}

	print_iterator(lis);

	std::cout << "\n\n";
	remove_vec(lis);
}
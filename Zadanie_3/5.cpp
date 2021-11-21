#include <random>
#include <iostream>
#include <ctime>
#include <list>
#include <algorithm>
#include <cmath>

int randomInt(int min, int max) {
	static std::default_random_engine e{ static_cast<long unsigned int>(time(0)) };
	std::uniform_int_distribution<int> d{ min, max };
	return d(e);
}

void print_iterator(std::list<int>& l) {

	for (auto it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << ",";
	}
	std::cout << "\n\n";
}

int main() {
	size_t N = 40;
	std::list<int> l;

	for (size_t i = 0; i < N; ++i) {
		l.push_back(randomInt(-20, 20));
	}

	print_iterator(l);
	l.sort();
	print_iterator(l);
	l.sort(std::greater<int>());
	print_iterator(l);
	l.sort([](int l, int r) { return std::abs(l) < std::abs(r); });
	print_iterator(l);

	std::cout << "\n\n";
}
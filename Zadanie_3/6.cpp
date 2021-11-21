#include <random>
#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <algorithm>

int randomInt(int min, int max) {
	static std::default_random_engine e{ static_cast<long unsigned int>(time(0)) };
	std::uniform_int_distribution<int> d{ min, max };
	return d(e);
}

int main() {
	size_t N = 40;
	std::vector<int> vec;
	std::list<int> l;

	for (size_t i = 0; i < N; ++i) {
		vec.push_back(randomInt(-20, 20));
	}
	std::cout<<"vec: \n";
	for (int i = -20; i <= 20; i++) {
		std::cout << "liczby " << i << "jest: " << std::count(vec.begin(), vec.end(), i) << "\n";
	}
	std::cout << "\nlista: \n";
	for (size_t i = 0; i < N; ++i) {
		l.push_back(randomInt(-20, 20));
	}

	for (int i = -20; i <= 20; i++) {
		std::cout << "liczby " << i << "jest: " << std::count(l.begin(), l.end(), i) << "\n";
	}
}
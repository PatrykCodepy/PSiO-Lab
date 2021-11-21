#include <random>
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <list>

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

	for (size_t i = 0; i < N; ++i) {
		l.push_back(randomInt(-20, 20));
	}

	std::vector<int>::iterator resultmin = std::min_element(vec.begin(), vec.end());
	std::vector<int>::iterator resultmax = std::max_element(vec.begin(), vec.end());

	std::cout << "min vec: " << vec[std::distance(vec.begin(), resultmin)] << std::endl;
	std::cout << "max vec: " << vec[std::distance(vec.begin(), resultmax)] << std::endl;

	std::list<int>::iterator resultmin2 = std::min_element(l.begin(), l.end());
	std::list<int>::iterator resultmax2 = std::max_element(l.begin(), l.end());

	std::cout << "max list: " << *resultmin2 << std::endl;
	std::cout << "max list: " << *resultmax2 << std::endl;

	auto result = std::minmax_element(begin(vec), end(vec));
	std::cout << "min vec = " << *result.first << ", max vec = " << *result.second << '\n';

	auto result = std::minmax_element(begin(l), end(l));
	std::cout << "min vec = " << *result.first << ", max vec = " << *result.second << '\n';
}
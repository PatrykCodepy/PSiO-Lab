#include <random>
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

int randomInt(int min, int max) {
	static std::default_random_engine e{ static_cast<long unsigned int>(time(0)) };
	std::uniform_int_distribution<int> d{ min, max };
	return d(e);
}	

void print_index(std::vector<int>& v, size_t n) {

	for (size_t i = 0; i < n; ++i) {
		std::cout << v[i] << std::endl;
	}
}

void print_iterator(std::vector<int>& v) {

	for (auto it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << std::endl;
	}
}


void remove_vec(std::vector<int>& v) {
	int x;
	std::cout << "Podaj liczbe: " << std::endl;
	std::cin >> x;

	for (auto it = v.begin(); it != v.end(); ++it) {
		if (*it == x) { it = v.erase(it) - 1; }
	}

}

int main() {
	size_t N = 40 ;
	std::vector<int> vec;

	for (size_t i = 0; i < N; ++i) {
		vec.push_back(randomInt(-20,20));
	}

	print_index(vec, N);

	std::cout << "\n\n";

	print_iterator(vec);

	std::cout << "\n\n";
	remove_vec(vec);
}
#include <iostream>
#include <string>
#include <vector>

std::vector<size_t> find_all(std::string input, char a) {
	size_t position = 0;
	std::vector<size_t> New = {};
	while ((position = input.find(a, position + 1)) != std::string::npos) {
		New.push_back(position);
	}
	return New;
}

int main() {
	std::string input = "Ala ma kota";

	std::vector<size_t> pos = find_all(input, 'a'); // wynik: {2, 5, 10}
	for (auto i : pos) std::cout << i << '\n';
}
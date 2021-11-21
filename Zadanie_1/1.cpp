#include <iostream>
#include <vector>

void fill_progressive(std::vector<int> &input) {
	for (std::size_t index = 0; index < input.size(); ++index) {
		input[index] = index+1;
	}
}

void print_vector(const std::vector<int> &input) {
	for (std::size_t index = 0; index < input.size(); ++index) {
		std::cout << input[index];
		if (index != input.size()-1) std::cout << ",";

	}
}

int main(){
	std::size_t n;
	std::cout << "Podaj n: ";
	std::cin >> n;

	std::vector<int> vec(n);

	fill_progressive(vec);
	print_vector(vec);
	return 1;
}
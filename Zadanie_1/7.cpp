#include <iostream>
#include <vector>

void draw_square(std::size_t n, bool left_diagonal, bool right_diagonal) {

	std::vector<char> vec;
	std::vector<std::vector<char>> matrix;

	for (std::size_t i = 1; i <= n; i++) {
		for (std::size_t j = 1; j <= n; j++) {
			if (i == n - j + 1 && right_diagonal == true) vec.push_back('#');
			else
			if (i == j && left_diagonal == true) vec.push_back('#');
			else
			if (i == n || j == n || i == 1 || j == 1) vec.push_back('#');
			else vec.push_back(' '); 
			//else vec.push_back(' ');
		}
		matrix.push_back(vec);
		vec.clear();
	}

	for (auto i: matrix)
	{
		for (auto j : i)	
		{
			std::cout << j;
		}
		std::cout << '\n';
	}
}

int main() {
	draw_square(7, true, true);
	return 1;
}
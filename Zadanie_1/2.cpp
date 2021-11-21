#include <iostream>
#include <vector>

void min_max(const std::vector<double>& input, double& min, double& max) {
	for (std::size_t index = 0; index < input.size(); ++index) {
		if (max < input[index])
			max = input[index];
		if (min > input[index])
			min = input[index];
	}
}

int main() {
	std::vector<double> values = { -1.0, 100, 3.14, -999.9, 21.37 };
	double min = values[0];
	double max = values[0];

	min_max(values, min, max);
	std::cout << "Maksimum: " << max << '\n' << "Minimu:" << min;
	return 1;
}
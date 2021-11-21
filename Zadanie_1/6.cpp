#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <cmath>

double pi_leibniz(double stop) {
	int pi = 3141, beta = 0;
	double x = 0, j = 1;
	std::size_t i = 0;
	while (beta != pi) {
		++i;
		if (i % 2 == 1) x += (1 / j);
		else x -= (1 / j);
		beta = (4 * x) / stop;
		j += 2;
	}
	return 4 * x;
}

int main() {
	double stop_at = 0.001;
	double pi_approx = pi_leibniz(stop_at);

	std::cout << pi_approx << std::endl;
	std::cout << "error: " << pi_approx - M_PI << std::endl;
	return 1;
}

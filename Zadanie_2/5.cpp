#include <iostream>
#include <string>
#include <vector>

std::string find_and_replace(std::string input, const std::string& x, const std::string& y) {
	size_t start_pos = 0;
	while ((start_pos = input.find(x, start_pos)) != std::string::npos) {
		input.replace(start_pos, x.length(), y);
		start_pos += y.length();
	}
	return input;
}
int main() {
	std::string input = "Ala ma kota, kot zjadl Ale!";
	std::string output = find_and_replace(input, "kot", "hefalump");
	std::cout << output;
	// wynik: "Ala ma hefalumpa, hefalump zjadl Ale!"
}
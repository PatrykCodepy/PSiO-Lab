#include <iostream>
#include <string>
#include <vector>

std::string find_longest_word(std::string input) {
	std::vector<size_t> vec = { 0 }, vec2;
	size_t position = 0, max = 0, j = 0, y=0;
	while ((position = input.find(' ', position + 1)) != std::string::npos) {
		vec.push_back(position);
	}
	vec.push_back(input.length() + 1);
	while(j+1 != vec.size()) {
		vec2.push_back((vec[j+1] - vec[j]));
		if (max < vec2[j]) {
			max = vec2[j];
			y = j;
		}
		j++;
	}
	return input.substr(vec[y], max);;
}

int main() {
	std::string input = "Ala ma kota kot jezdzi na Roombie";
	std::string longest = find_longest_word(input); // "Roombie"
	std::cout << longest;
}
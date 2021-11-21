#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string word, char option) {
	int i=0;
	std::string x;
	std::vector<std::string> vec;
	
	while (i < word.length()) {
		if (word.at(i) == option) {
			vec.push_back(x);
			x.clear();
		}
		else {
			x += (word.at(i));
		}
		i++;
	}
	vec.push_back(x);
	x.clear();
	return vec;
}

int main() {
	std::string sentence = "Ala ma kota";
	std::vector<std::string> words = split(sentence, ' '); // wynik: {"Ala", "ma", "kota"}
	for (auto j : words) {
		std::cout << j << '\n';
	}
	std::cout << std::endl << std::endl;
	std::string csv = "Mount Everest,8848,1953";
	std::vector<std::string> data = split(csv, ','); // wynik: {"Mount Everest", "8848", "1953"}
	for (auto j : data) {
		std::cout << j << '\n';
	}
}
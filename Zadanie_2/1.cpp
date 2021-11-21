#include <iostream>
#include <string>

bool is_palindrome(std::string word) {
    size_t x = word.length() - 1;
    bool l;
    for (size_t i = 0; i < word.length(); i++) {
        if (word[i] != word[x-i]) l = false;
        else l = true;
    }
    return l;
}

int main() {
    std::string word = "racecar";
    if (is_palindrome(word)) {
        std::cout << "To palindrom!" << std::endl;
    }
    else {
        std::cout << "Nope" << std::endl;
    }
}
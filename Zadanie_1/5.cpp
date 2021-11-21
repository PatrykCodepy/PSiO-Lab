#include <iostream>
#include <vector>
#include <cmath>

bool is_prime(std::size_t g, std::size_t d, std::vector<std::size_t> &num) {
    int tmp = 0;
    for (std::size_t j = d; j <= g; j++) {
        for (std::size_t i = d; i <= sqrt(j); i++)
            if (j % i == 0) tmp += 1;
        if (tmp == 1) {
            num.push_back(j);
        }
        tmp = 0;
    }
    return 1;
}

int main() {
    //int prime_or_not_prime = 13;
    std::size_t g, d;
    std::vector<std::size_t> num = {};
    std::cout << "Podaj dolny i gorny zakres: " << '\n';
    std::cin >> d >> g;
    if(d<g && d < 0 && g < 0){
    if (is_prime(g, d, num)) {
        for (const auto i : num)
            std::cout << i << " ";
        std::cout << " is prime!" << std::endl;
    }
    }else std::cout << "Zly zakres";
   /* else {
        std::cout << num << " is not prime!" << std::endl;
    }*/
    return 1;
}

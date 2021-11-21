#include <iostream>
#include <vector>
void bubbleSort(std::vector<double> &vec)
{
    int i, j;
    double x;
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - i - 1; j++)
            if (vec[j] > vec[j + 1]) {
                x = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = x;
                x = 0;
            }
    }
}

int main() {
	std::vector<double> vec = {10, 20 , -12, 531, -532, 55, 0 , 1};
    bubbleSort(vec);
    for (auto i : vec) {
        std::cout << i << '\n';
    }
}
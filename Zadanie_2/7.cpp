#include <iostream>
#include <vector>

int binary_search(std::vector<double> vec, int first, int last, int search_num)
{
    int middle;
    if (last >= first)
    {
        middle = (first + last) / 2;
        if (vec[middle] == search_num)
        {
            return middle + 1;
        }
        else if (vec[middle] < search_num)
        {
            return binary_search(vec, middle + 1, last, search_num);
        }
        else
        {
            return binary_search(vec, first, middle - 1, search_num);
        }

    }
    return -1;
}

int main()
{
    std::vector<double> vec = { 1,2,4,6,7,9,10,15,16 };
    int search_num= 10, loc = -1;

    loc = binary_search(vec, 0, vec.size(), search_num);

    if (loc != -1)
    {
        std::cout << search_num << " miesci sie na pozycjo: " << loc;
    }
    else
    {
        std::cout << "Nie ma takiego elementu";
    }
    return 0;
}
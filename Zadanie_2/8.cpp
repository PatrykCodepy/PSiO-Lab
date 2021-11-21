#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct Exchange_rate
{
    std::string date;
    double usd;
    double eur;
    std::string table_id;
};

void sort_usd(std::vector<Exchange_rate>& vec)
{
    int i, j;
    double x;
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - i - 1; j++)
            if (vec[j].usd > vec[j + 1].usd) {
                x = vec[j].usd;
                vec[j].usd = vec[j + 1].usd;
                vec[j + 1].usd = x;
                x = 0;
            }
    }
}

void sort_eur(std::vector<Exchange_rate>& vec)
{
    int i, j;
    double x;
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - i - 1; j++)
            if (vec[j].eur > vec[j + 1].eur) {
                x = vec[j].eur;
                vec[j].eur = vec[j + 1].eur;
                vec[j + 1].eur = x;
                x = 0;
            }
    }
}

int binary_search(std::vector<Exchange_rate> vec, int first, int last, double search_num)
{
    int middle;
    if (last >= first)
    {
        middle = (first + last) / 2;
        if (vec[middle].usd == search_num)
        {
            return middle + 1;
        }
        else if (vec[middle].usd < search_num)
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

int main() {
    std::fstream file("kursy_usd_eur.csv", std::fstream::in);
    std::vector<Exchange_rate> rates;
    if (file.is_open()) {
        std::string line;
        std::getline(file, line); // wczytuje pierwszą linię z nagłówkiem i ją ignoruje
        while (std::getline(file, line)) {//wczytuje kolejne linie aż do końca pliku
            std::stringstream str(line);//tworzy strumień, którego źródłem jest wczytana linia

            Exchange_rate er;
            std::getline(str, er.date, ','); //wczytuje date (pierwszy element wiersza)
            std::string double_str;
            std::getline(str, double_str, ',');  // wczytuje kurs USD (jako tekst)
            er.usd = std::stod(double_str);      //zamiana na string->double
            std::getline(str, double_str, ',');  // wczytuje kurs EUR (jako tekst)
            er.eur = std::stod(double_str);      //zamiana na string->double
            std::getline(str, er.table_id, ','); // wczytuje ostatnią kolumnę z numerem tabeli NBP
            rates.emplace_back(er); //dodaje element do kolekcji
        }
    }
    sort_usd(rates);
    sort_eur(rates);
    int j = 0 ;
    for (auto i : rates) {
        if((rates.size() - 11) < j) std::cout << i.date << " " << i.usd << '\n';
        j++;
    }
    j = 0;
    std::cout << std::endl;
    for (auto i : rates) {
        if ((rates.size() - 11) < j) std::cout << i.date << " " << i.eur << '\n';
        j++;
    }

    double search_num = 3.9011;
    int loc = -1;

    loc = binary_search(rates, 0, rates.size(), search_num);

    if (loc != -1)
    {
        std::cout << search_num << " dnia: " << rates[loc].date;
    }
    else
    {
        std::cout << "Nie ma takiego elementu";
    }
}
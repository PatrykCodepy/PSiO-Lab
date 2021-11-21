#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <string>

struct Exchange_rate
{
    std::string date;
    double usd;
    double eur;
    std::string table_id;
};

void sort_usd(std::vector<Exchange_rate>& rates) {
    std::sort(rates.begin(), rates.end(),
        [](Exchange_rate& a, Exchange_rate& b) {return a.usd < b.usd; }
    );
}

void sort_eur(std::vector<Exchange_rate>& rates) {
    std::sort(rates.begin(), rates.end(),
        [](Exchange_rate& a, Exchange_rate& b) {return a.eur < b.eur; }
    );
}

void write_usd(std::vector<Exchange_rate>& rates) {
    int j = 0;
    for (auto i : rates) {
        if ((rates.size() - 11) < j) std::cout << i.date << " " << i.usd << '\n';
        j++;
    }
    j = 0;
}

void write_eur(std::vector<Exchange_rate>& rates) {
    int j = 0;
    for (auto i : rates) {
        if ((rates.size() - 11) < j) std::cout << i.date << " " << i.eur << '\n';
        j++;
    }
    j = 0;
}

void binary_search(std::vector<Exchange_rate>& rates) {

    struct Comp
    {
        bool operator() (const Exchange_rate& a, double b) const { return a.usd < b; };
        bool operator() (double a, const Exchange_rate& b) const { return a < b.usd; };
    };
    //Exchange_rate search_num = { "?", 3.9011, 0, "?" };
    //double search_num = 3.9011;
    //auto p = std::equal_range(rates.begin(), rates.end(), search_num, Comp{});
    auto p = std::equal_range(rates.begin(), rates.end(), 3.9011, Comp{});
    std::cout << rates[p.first - rates.begin()].date << std::endl;
    std::cout << rates[p.first - rates.begin()].usd << std::endl;
    std::cout << rates[p.first - rates.begin()].eur << std::endl;
    std::cout << rates[p.first - rates.begin()].table_id << std::endl;
}

void wczytanie(std::vector<Exchange_rate>& rates, std::string filename){
    std::fstream file(filename, std::fstream::in);
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
}

int main() {
    std::vector<Exchange_rate> rates;
    wczytanie(rates, "kursy_usd_eur.csv");
    
    sort_usd(rates);

    binary_search(rates);

    write_usd(rates);

    //sort_eur(rates);

    //write_eur(rates);
}
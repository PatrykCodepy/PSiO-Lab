#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

enum class TypRosliny { Owoc, Warzywo };

struct Roslina {
    TypRosliny typ;
    std::string nazwa;
};

using Koszyk = std::vector<Roslina>;

//zadanie 7
void add(Koszyk &vec) {

    vec.push_back(Roslina());
    vec[0].typ = TypRosliny::Owoc;
    vec[0].nazwa = "Kiwi";

    vec.push_back(Roslina{ TypRosliny::Owoc, "Banan" });

    vec.emplace_back(Roslina{ TypRosliny::Warzywo, "Papryka" });

    Roslina Ananas = { TypRosliny::Owoc, "Ananas" };
    vec.push_back(Ananas);
    
    vec.push_back(Roslina());
    vec[vec.size() - 1].typ = TypRosliny::Warzywo;
    vec[vec.size() - 1].nazwa = "Pomidor";

    Roslina y;
    y.typ = TypRosliny::Warzywo;
    y.nazwa = "Fasola";
    vec.push_back(y);

    auto lam = [](Roslina x) mutable -> Roslina {x.typ = TypRosliny::Owoc; x.nazwa = "Gruszka"; return x; }(y);
    vec.push_back(lam);
}

//zadanie 8
std::ostream& operator<<(std::ostream& out, const Roslina& roslina) {
    out << (int(roslina.typ) ? "Warzywo" : "Owoc") << roslina.nazwa;
    return out;
}
//zadanie 8
std::ostream& operator<<(std::ostream& out, const Koszyk& koszyk) { 
    for (auto i : koszyk) {
        out << (int(i.typ) ? "Warzywo" : "Owoc") << ": " << i.nazwa << "\n";
    }
    return out;
}

//zadanie 9
bool czy_jest_gruszka(const Koszyk& koszyk) { 
    auto result = std::find_if(begin(koszyk), end(koszyk), 
        [](Roslina i) ->bool{ return i.nazwa == "Gruszka" || i.nazwa == "gruszka"; }
        );

    return (result != std::end(koszyk)) ? true : false;
}

//zadanie 10
bool czy_same_owoce(const Koszyk& koszyk) {
    return std::all_of(koszyk.begin(), koszyk.end(),
        [](const Roslina& roslina) { return roslina.typ == TypRosliny::Owoc; }
    );
}

bool czy_same_warzywa(const Koszyk& koszyk) {
    return std::all_of(koszyk.begin(), koszyk.end(),
        [](const Roslina& roslina) { return roslina.typ == TypRosliny::Warzywo  ; }
    );
}

bool co_najmniej_jedn_owoc(const Koszyk& koszyk) {
    return std::any_of(koszyk.begin(), koszyk.end(),
        [](const Roslina& roslina) { return roslina.typ == TypRosliny::Owoc; }
    );
}

bool co_najmniej_jedno_warzywo(const Koszyk& koszyk) {
    return std::any_of(koszyk.begin(), koszyk.end(),
        [](const Roslina& roslina) { return roslina.typ == TypRosliny::Warzywo; }
    );
}

bool zadnego_owocu(const Koszyk& koszyk) {
    return std::none_of(koszyk.begin(), koszyk.end(),
        [](const Roslina& roslina) { return roslina.typ == TypRosliny::Owoc; }
    );
}

bool zadnego_warzywa(const Koszyk& koszyk) {
    return std::none_of(koszyk.begin(), koszyk.end(),
        [](const Roslina& roslina) { return roslina.typ == TypRosliny::Warzywo; }
    );
}

void mama_sprawdza(const Koszyk& koszyk) {
    if (czy_same_owoce(koszyk)) { std::cout << "Same owoce \n"; }
    if (czy_same_warzywa(koszyk)) { std::cout << "Same warzywa \n"; }
    if (co_najmniej_jedn_owoc(koszyk)) { std::cout << "Co najmniej jedn owoc \n"; }
    if (co_najmniej_jedno_warzywo(koszyk)) { std::cout << "Co najmniej jedno warzywo \n"; }
    if (zadnego_owocu(koszyk)) { std::cout << "Zadnego owocu \n"; }
    if (zadnego_warzywa(koszyk)) { std::cout << "Zadnego warzywa \n"; }
}

//zadanie 11
int zlicz_owoce(const Koszyk& koszyk) {
    return std::count_if(koszyk.begin(), koszyk.end(),
        [](const Roslina& roslina) { return roslina.typ == TypRosliny::Owoc; }
    );
}

int zlicz_warzywa(const Koszyk& koszyk) {
    return std::count_if(koszyk.begin(), koszyk.end(),
        [](const Roslina& roslina) { return roslina.typ == TypRosliny::Warzywo; }
    );
}

//zadanie 12
void usun_zaczynajace_sie_od(Koszyk& koszyk) {

    koszyk.erase(
        std::remove_if(koszyk.begin(),koszyk.end(),
        [](const Roslina& roslina) {return roslina.nazwa[0] == 'G' || roslina.nazwa[0] == 'g'; }));
}

//zadanie 13
bool operator<(const Roslina& r1, const Roslina& r2) { 
    if (r1.typ != r2.typ) {
        return r1.typ < r2.typ;
    }
    else {
        return r1.nazwa < r2.nazwa;
    }
}

int main() {
    Koszyk koszyk;

    add(koszyk);

    std::cout << koszyk;

    if (czy_jest_gruszka(koszyk)) { std::cout << "Sa gruszki! \n"; }
    else { std::cout << "Nie ma gruszki! \n"; }
    mama_sprawdza(koszyk);
    std::cout << "Owocow jest liczba: " << zlicz_owoce(koszyk) << " \nWarzyw jest liczba: " << zlicz_warzywa(koszyk);
    usun_zaczynajace_sie_od(koszyk);

    //zdanie 14
    Koszyk Marta{
      {TypRosliny::Owoc, "Banan"},
      {TypRosliny::Warzywo, "Burak"},
      {TypRosliny::Owoc, "Jalko"},
      {TypRosliny::Warzywo, "Ziemniak"},
      {TypRosliny::Owoc, "Sliwka"}
    };

    std::sort(koszyk.begin(), koszyk.end());
    std::sort(Marta.begin(), Marta.end());

    Koszyk wspolny;

    Koszyk koszyk_wspolne;
    std::set_intersection(koszyk.begin(), koszyk.end(),
        Marta.begin(), Marta.end(),
        std::back_inserter(koszyk_wspolne));

    std::cout << "\n Wspolne: " << koszyk_wspolne << std::endl;

    Koszyk koszyk_roznic;
    std::set_difference(koszyk.begin(), koszyk.end(),
        Marta.begin(), Marta.end(),
        std::back_inserter(koszyk_roznic));
    std::set_difference(Marta.begin(), Marta.end(),
        koszyk.begin(), koszyk.end(),
        std::back_inserter(koszyk_roznic));

    std::cout << "\n Wspolne: " << koszyk_roznic << std::endl;

    //zdanie 15
    Koszyk wspolne;

    std::set_union(koszyk.begin(), koszyk.end(),
        Marta.begin(), Marta.end(),
        std::back_inserter(wspolne));

    std::cout << "\n Wspolne: " << wspolne << std::endl;
}
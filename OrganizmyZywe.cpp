#include <string>
#include <iostream>

#include "OrganizmyZywe.hpp"


using namespace std;

OrganizmyZywe::OrganizmyZywe()
{

}


OrganizmyZywe::~OrganizmyZywe()
{

}




void OrganizmyZywe::edytuj ()
{

    cout << "Jakiego gatunku jest ten organizm? ";
    getline( cin, gatunek);
    cout << "Podaj specyfikacje gatunku? ";
    getline( cin, specyfikacja);

}

void OrganizmyZywe::wyswietl()
{
    cout << "Nazwa organizmu: " << nazwa << endl;
}

void OrganizmyZywe::wyswietlWszy()
{
    cout << "Nazwa organizmu: " << nazwa << endl;
    cout << "Gatunek organizmu: " << gatunek << endl;
    cout << "Specyfikacja gatunku: " << specyfikacja << endl;
}

string OrganizmyZywe::dajNazwe()
{
    return this->nazwa;
}

void OrganizmyZywe::ustawNazwa(string nazwa)
{
    this->nazwa = nazwa;
}

string OrganizmyZywe::dajWszystkieDelimitowane()
{
    string wszyDelim;
    wszyDelim = nazwa + ";" + gatunek + ";" + specyfikacja;
    return wszyDelim;
}

void OrganizmyZywe::ustawWszystkiePola(string p_nazwa, string p_gatunek, string p_specyfikacja)
{
  nazwa = p_nazwa;
  gatunek = p_gatunek;
  specyfikacja = p_specyfikacja;
}

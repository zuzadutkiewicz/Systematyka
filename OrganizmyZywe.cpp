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


void OrganizmyZywe::jedz()
{

}

void OrganizmyZywe::rozmnazanie()
{

}


void OrganizmyZywe::edytuj ()
{

    cout << "Jak ma na imie ten organizm? ";
    getline( cin, imie);
    cout << "Co lubi ten orgaznim? ";
    getline( cin, coLubi);

}

void OrganizmyZywe::wyswietl()
{
    cout << "Nazwa organizmu: " << nazwa << endl;
}

void OrganizmyZywe::wyswietlWszy()
{
    cout << "Nazwa organizmu: " << nazwa << endl;
    cout << "Imie organizmu: " << imie << endl;
    cout << "Organizm ten lubi: " << coLubi << endl;
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
    wszyDelim = nazwa + ";" + imie + ";" + coLubi;
    return wszyDelim;
}

void OrganizmyZywe::ustawWszystkiePola(string p_nazwa, string p_imie, string p_coLubi)
{
  nazwa = p_nazwa;
  imie = p_imie;
  coLubi = p_coLubi;
}

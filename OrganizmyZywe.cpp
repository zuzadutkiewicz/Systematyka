#include <string>
#include <iostream>

#include "OrganizmyZywe.hpp"


using namespace std;


void OrganizmyZywe::iloscGatunkow()
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

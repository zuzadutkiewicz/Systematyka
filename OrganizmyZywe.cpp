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
    printf("Jak nazywa sie ten organizm? ");
    scanf("%s", nazwa);
    printf("Co lubi ten orgaznim? ");
    scanf("%s", coLubi);

}

void OrganizmyZywe::wyswietl()
{
    printf("Nazwa tego organizmu to: %s\n", nazwa);
}

void OrganizmyZywe::wyswietlWszy()
{
    printf("Nazwa organizmu to: %s\n", nazwa);
    printf("Organizm ten lubi: %s\n", coLubi);
}

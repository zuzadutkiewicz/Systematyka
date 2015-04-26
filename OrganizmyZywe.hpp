#ifndef ORGANIZMYZYWE_HPP_INCLUDED
#define ORGANIZMYZYWE_HPP_INCLUDED

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class OrganizmyZywe
{
public:
    OrganizmyZywe();
    virtual ~OrganizmyZywe();
    OrganizmyZywe *nastepny;
    void jedz();
    void rozmnazanie();
    virtual void edytuj();
    virtual void wyswietl();
    virtual void wyswietlWszy();
    virtual string dajNazwe();
    virtual void ustawNazwa(string nazwa);
    virtual string dajWszystkieDelimitowane();
    virtual void ustawWszystkiePola(string nazwa, string imie, string coLubi);

protected:
    string nazwa;
    string gatunek;


private:
    string nazwaKlasy;
    string specyfikacja;
};

#endif // ORGANIZMYZYWE_HPP_INCLUDED

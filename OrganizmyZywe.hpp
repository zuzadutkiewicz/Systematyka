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
    OrganizmyZywe *nastepny;
    void jedz();
    void rozmnazanie();
    string nazwa;
    string imie;
    string coLubi;
    virtual void edytuj();
    virtual void wyswietl();
    virtual void wyswietlWszy();



private:
    void iloscGatunkow();
};

#endif // ORGANIZMYZYWE_HPP_INCLUDED

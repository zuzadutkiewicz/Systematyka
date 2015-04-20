#ifndef ORGANIZMYZYWE_HPP_INCLUDED
#define ORGANIZMYZYWE_HPP_INCLUDED

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>



class OrganizmyZywe
{
public:
    void jedz();
    void rozmnazanie();
    char nazwa [100];
    char coLubi [100];
    virtual void edytuj();
    virtual void wyswietl();
    virtual void wyswietlWszy();



private:
    void iloscGatunkow();
};

#endif // ORGANIZMYZYWE_HPP_INCLUDED

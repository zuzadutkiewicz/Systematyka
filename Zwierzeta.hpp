#ifndef ZWIERZETA_HPP_INCLUDED
#define ZWIERZETA_HPP_INCLUDED

#include "OrganizmyZywe.hpp"

class Zwierzeta :public OrganizmyZywe
{
public:

    void heterotrofy();

protected:
    string nazwa;
    string imie;


private:
    string nazwaKlasy;
    string coLubi;

};


#endif // ZWIERZETA_HPP_INCLUDED

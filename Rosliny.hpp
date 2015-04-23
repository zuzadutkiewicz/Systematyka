#ifndef ROSLINY_HPP_INCLUDED
#define ROSLINY_HPP_INCLUDED

#include "OrganizmyZywe.hpp"

class Rosliny : public OrganizmyZywe
{
public:
    void autotrofy();

protected:
    string nazwa;
    string imie;



private:
    string nazwaKlasy;
    string coLubi;
};

#endif // ROSLINY_HPP_INCLUDED

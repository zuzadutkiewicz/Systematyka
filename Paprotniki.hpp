#ifndef PAPROTNIKI_HPP_INCLUDED
#define PAPROTNIKI_HPP_INCLUDED

#include "Zarodnikowe.hpp"

class Paprotniki : public Zarodnikowe
{
public:
    void rozsiewajZarodniki();

protected:
    string nazwa;
    string imie;


private:
    string nazwaKlasy;
    string coLubi;

} ;
#endif // PAPROTNIKI_HPP_INCLUDED

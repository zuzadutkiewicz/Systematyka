#ifndef MSZAKI_HPP_INCLUDED
#define MSZAKI_HPP_INCLUDED

#include "Zarodnikowe.hpp"

class Mszaki : public Zarodnikowe
{
public:
    void tworzZarodnie();

protected:
    string nazwa;
    string imie;



private:
    string nazwaKlasy;
    string coLubi;
};


#endif // MSZAKI_HPP_INCLUDED

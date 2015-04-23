#ifndef MCHY_HPP_INCLUDED
#define MCHY_HPP_INCLUDED

#include "Mszaki.hpp"

class Mchy : public Mszaki
{
public:
    void specyfikacjaGatunku ();

protected:
    string nazwa;
    string imie;


private:
    string nazwaKlasy;
    string coLubi;
} ;

#endif // MCHY_HPP_INCLUDED

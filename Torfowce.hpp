#ifndef TORFOWCE_HPP_INCLUDED
#define TORFOWCE_HPP_INCLUDED

#include "Mszaki.hpp"

class Torfowce : public Mszaki
{
public:
    void specyfikacjaGatunku ();

protected:
    string nazwa;
    string imie;


private:
    string nazwaKlasy;
    string coLubi;


};


#endif // TORFOWCE_HPP_INCLUDED

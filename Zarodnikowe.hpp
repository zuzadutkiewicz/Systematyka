#ifndef ZARODNIKOWE_HPP_INCLUDED
#define ZARODNIKOWE_HPP_INCLUDED

#include "Rosliny.hpp"

class Zarodnikowe : public Rosliny
{
public:
    void produkujZarodniki();

protected:
    string nazwa;
    string imie;


private:
    string nazwaKlasy;
    string coLubi;
};

#endif // ZARODNIKOWE_HPP_INCLUDED

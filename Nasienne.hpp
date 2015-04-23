#ifndef NASIENNE_HPP_INCLUDED
#define NASIENNE_HPP_INCLUDED

#include "Rosliny.hpp"

class Nasienne : public Rosliny
{
    public:
    void produkujNasiona();

protected:
    string nazwa;
    string imie;


private:
    string nazwaKlasy;
    string coLubi;
};

#endif // NASIENNE_HPP_INCLUDED

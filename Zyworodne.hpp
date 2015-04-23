#ifndef DRAPIEZNIKI_HPP_INCLUDED
#define DRAPIEZNIKI_HPP_INCLUDED

#include "OrganizmyZywe.hpp"
#include "Zwierzeta.hpp"

class Zyworodne : public Zwierzeta
{
public:
    void poluj();

protected:
    string nazwa;
    string imie;

private:
    string nazwaKlasy;
    string coLubi;

};
#endif // DRAPIEZNIKI_HPP_INCLUDED

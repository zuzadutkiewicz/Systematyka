#ifndef DRAPIEZNIKI_HPP_INCLUDED
#define DRAPIEZNIKI_HPP_INCLUDED

#include "OrganizmyZywe.hpp"
#include "Zwierzeta.hpp"

class Zyworodne : public Zwierzeta
{
public:
protected:
    string nazwa;
    string gatunek;

private:
    string nazwaKlasy;
    string specyfikacja;

};
#endif // DRAPIEZNIKI_HPP_INCLUDED

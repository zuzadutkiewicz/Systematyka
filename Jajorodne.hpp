#ifndef ROSLINOZERCY_HPP_INCLUDED
#define ROSLINOZERCY_HPP_INCLUDED

#include "Zwierzeta.hpp"

class Jajorodne : public Zwierzeta
{
public:
    void szukajJedzenia();

protected:
    string nazwa;
    string imie;


private:
    string nazwaKlasy;
    string coLubi;

};

#endif // ROSLINOZERCY_HPP_INCLUDED

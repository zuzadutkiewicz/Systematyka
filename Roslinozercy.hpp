#ifndef ROSLINOZERCY_HPP_INCLUDED
#define ROSLINOZERCY_HPP_INCLUDED

#include "Zwierzeta.hpp"

class Roslinozercy : public Zwierzeta
{
public:
    void szukajJedzenia();

private:
    void nieJedzTru();
};

#endif // ROSLINOZERCY_HPP_INCLUDED

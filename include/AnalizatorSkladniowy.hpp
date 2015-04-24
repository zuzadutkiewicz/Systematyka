#ifndef ANALIZATORSKLADNIOWY_HPP
#define ANALIZATORSKLADNIOWY_HPP

#include <iostream>
#include <Tokeny.hpp>

using namespace std;

class AnalizatorSkladniowy
{
    public:
        string polecenie;
        Tokeny *tokeny;
        AnalizatorSkladniowy(Tokeny *p_tokeny, string polecenie);
        virtual ~AnalizatorSkladniowy();
        bool analizuj();
        Tokeny* dajTokeny();
    protected:
    private:
        bool sprawdzPolecenie(int opcjeMin, int opcjeMax);
};

#endif // ANALIZATORSKLADNIOWY_HPP

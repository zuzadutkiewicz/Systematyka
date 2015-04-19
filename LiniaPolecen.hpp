#ifndef LINIAPOLECEN_HPP_INCLUDED
#define LINIAPOLECEN_HPP_INCLUDED

#include "include/Drzewo.hpp"

class LiniaPolecen
{

public:
    typedef struct Token
    {
        char opcja[200];
        struct Token *nastepny;
    } Token;
    Drzewo drzewo;
    void liniaPolecen();
    Token * dajTokeny(char *opcja, Token *root);
    void usunTokeny(Token *root);
    void wyswietlTokeny(Token *root);
    void help();

};

#endif // LINIAPOLECEN_HPP_INCLUDED

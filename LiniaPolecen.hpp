#ifndef LINIAPOLECEN_HPP_INCLUDED
#define LINIAPOLECEN_HPP_INCLUDED

#include "include/Drzewo.hpp"

class LiniaPolecen
{

public:
    typedef struct Token
    {
        string opcja;
        struct Token *nastepny;
    } Token;
    Drzewo drzewo;
    void liniaPolecen();
    Token * dajTokeny(string linia, Token *root);
    void usunTokeny(Token *root);
    void wyswietlTokeny(Token *root);
    bool czyToPolecenie(Token* root, string polecenie, int opcje);
    bool czyToPolecenie(Token* root, string polecenie, int opcjeMin, int opcjeMax);
    void help();

};

#endif // LINIAPOLECEN_HPP_INCLUDED

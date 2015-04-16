#ifndef LINIAPOLECEN_HPP_INCLUDED
#define LINIAPOLECEN_HPP_INCLUDED


class LiniaPolecen
{

public:
    typedef struct Token
    {
        char opcja[200];
        struct Token *nastepny;
    } Token;
    char nazwy[6][20];

    void liniaPolecen();
    Token * dajTokeny(char *opcja, Token *root);
    void usunTokeny(Token *root);
    void wyswietlTokeny(Token *root);
    void uzupelnijNazwy(char nazwy[6][20]);

};

#endif // LINIAPOLECEN_HPP_INCLUDED

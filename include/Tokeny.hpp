#ifndef TOKENY_HPP
#define TOKENY_HPP

#include <iostream>

#include <string>


using namespace std;

class Tokeny
{
public:
    typedef struct Token
    {
        string opcja;
        struct Token *nastepny;
    } Token;
    Token* root;
    Token* aktualnyToken;
    Tokeny();
    virtual ~Tokeny();
    void wyswietlTokeny();
    string dajToken();
    void ustawTokeny(string linia);
    void ustawRoot();
    void usunTokeny();
protected:
private:

};

#endif // TOKENY_H

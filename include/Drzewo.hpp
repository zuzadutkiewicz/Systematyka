#ifndef DRZEWO_H
#define DRZEWO_H

#include <string>

#include "../OrganizmyZywe.hpp"

using namespace std;


class Drzewo
{
public:
    struct Wezel
    {
        string nazwa;
        bool czyLisc;
        Wezel *lewy;
        Wezel *prawy;
        OrganizmyZywe *lista;
    };
    Wezel *root;
    Drzewo();
    virtual ~Drzewo();
    void utworzDrzewo();
    void wyswietlDrzewo();
    string dajNazwaAktualny();
    void ustawAktualnyWezel(string nazwaWezla);

protected:
private:
    Wezel *aktualny;
    void rekurWyswietlDrzewo(Wezel *wezel, int wysokosc);
    void rekurUstawAktualnyWezel(Wezel *wezel, string nazwaWezla);
};

#endif // DRZEWO_H

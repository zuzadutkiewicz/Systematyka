#ifndef DRZEWO_H
#define DRZEWO_H

#include <string>

#include "../OrganizmyZywe.hpp"
#include "../Jajorodne.hpp"
#include "../Zyworodne.hpp"
#include "../Nasienne.hpp"
#include "../Paprotniki.hpp"
#include "../Mchy.hpp"
#include "../Torfowce.hpp"



using namespace std;


class Drzewo
{
public:
    struct Wezel
    {
        string nazwa;
        Wezel *lewy;
        Wezel *prawy;
        OrganizmyZywe *lista;
    };
    Wezel *root;
    Drzewo();
    virtual ~Drzewo();
    void utworzDrzewo();
    void wyswietlDrzewo();
    void wyswietlDrzewo(string nazwaWezla);
    string dajNazwaAktualny();
    void ustawAktualnyWezel(string nazwaWezla);
    void dodajDoAktualny(string nazwa);
    void usunZAktualny(string nazwaObiektu);
    void edytujZAktualny(string nazwaObiektu);
    void wyswietlWszystkieZAltualny();
    void wyswietlWszystkieZWezla();
    void wyswietlWszystkieZWezla(string nazwaWezla);
    void wyswietlWszystkieZWezlaLiscia(Wezel *wezel);
    void rekurWyswietlWszystkieZWezla(Wezel* wezel,int wysokosc);
    void wyswietlObiektZAktualny(string nazwaObiektu);
    OrganizmyZywe* dajObiektLisc(string nazwaObiektu);



protected:
private:
    Wezel *aktualny;
    void rekurWyswietlDrzewo(Wezel *wezel, int wysokosc);
    Wezel* rekurDajWezel(Wezel *wezel, string nazwaWezla);
    void usunWszystko();
    void rekurUsunWszystko(Wezel* wezel);
    bool jestLisciem(Wezel* wezel);
    Wezel* dajWezel(string nazwaWezla);

};

#endif // DRZEWO_H

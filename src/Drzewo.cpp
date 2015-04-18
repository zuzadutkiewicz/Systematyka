#include <iostream>

#include "Drzewo.hpp"

Drzewo::Drzewo()
{
    utworzDrzewo();
    aktualny = root;
}

Drzewo::~Drzewo()
{
    usunWszystko();
}

void Drzewo::utworzDrzewo()
{
    Wezel *wezel = NULL;
    Wezel *wezelPoprz = NULL;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->nazwa = "organizmy";
    wezelPoprz = wezel;
    root = wezel;

    // galaz zwierzat

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->nazwa = "zwierzeta";
    wezelPoprz->lewy = wezel;
    wezelPoprz = wezel;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->nazwa = "drapiezniki";
    wezelPoprz->lewy = wezel;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->nazwa = "roslinozerne";
    wezelPoprz->prawy = wezel;

    // rosliny

    wezelPoprz = root;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->nazwa = "rosliny";
    wezelPoprz->prawy = wezel;

    wezelPoprz = wezel;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->nazwa = "nasienne";
    wezelPoprz->prawy = wezel;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->nazwa = "zarodnikowe";
    wezelPoprz->lewy = wezel;

    wezelPoprz = wezel;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->nazwa = "paprotniki";
    wezelPoprz->lewy = wezel;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->nazwa = "mszaki";
    wezelPoprz->prawy = wezel;

    wezelPoprz = wezel;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->nazwa = "mchy";
    wezelPoprz->lewy = wezel;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->nazwa = "torfowce";
    wezelPoprz->prawy = wezel;

}

void Drzewo::wyswietlDrzewo()
{
    int wysokosc = 1;
    Wezel* wezel = root;
    if (wezel == NULL)
        return;

    if(wezel!=NULL)
    {
        cout << string(wysokosc*3, ' ') << wezel->nazwa << endl;
        rekurWyswietlDrzewo(wezel->lewy, wysokosc);
        rekurWyswietlDrzewo(wezel->prawy, wysokosc);
    }

}

void Drzewo::rekurWyswietlDrzewo(Wezel* wezel,int wysokosc)
{

    if(wezel!=NULL)
    {
        wysokosc += 1;
        cout << string(wysokosc*3, ' ') << wezel->nazwa <<
        ((wezel->lewy == NULL && wezel->prawy == NULL) ? " (lisc)": " ") << endl;
        rekurWyswietlDrzewo(wezel->lewy, wysokosc);
        rekurWyswietlDrzewo(wezel->prawy, wysokosc);
    }
}

string Drzewo::dajNazwaAktualny()
{
    if( aktualny == NULL)
        return "(null)";
    return aktualny->nazwa;
}

void Drzewo::ustawAktualnyWezel(string nazwaWezla)
{
    Wezel* wezel = root;
    Wezel* aktualnyOld = aktualny;
    aktualny = NULL;
    if(wezel != NULL)
    {
        if (nazwaWezla.compare(wezel->nazwa) == 0)
            aktualny = wezel;
        else
        {
            rekurUstawAktualnyWezel(wezel->lewy, nazwaWezla);
            rekurUstawAktualnyWezel(wezel->prawy, nazwaWezla);
        }
    }
    if(aktualny ==  NULL)
    {
        aktualny = aktualnyOld;
        cout << "Niepoprawna nazwa wezla: " << nazwaWezla << endl;
    }
}

void Drzewo::rekurUstawAktualnyWezel(Wezel *wezel, string nazwaWezla)
{
    if(wezel != NULL)
    {
        if (nazwaWezla.compare(wezel->nazwa) == 0)
            aktualny = wezel;
        else
        {
            rekurUstawAktualnyWezel(wezel->lewy, nazwaWezla);
            rekurUstawAktualnyWezel(wezel->prawy, nazwaWezla);
        }
    }
}

void Drzewo::usunWszystko()
{
    Wezel* wezel = this->root;
    if(wezel!=NULL)
    {
        rekurUsunWszystko(wezel->lewy);
        rekurUsunWszystko(wezel->prawy);
        delete(wezel);
    }
    this->root = NULL;
}

void Drzewo::rekurUsunWszystko(Wezel* wezel)
{
    if(wezel!=NULL)
    {
        rekurUsunWszystko(wezel->lewy);
        rekurUsunWszystko(wezel->prawy);
        delete(wezel);
    }
}


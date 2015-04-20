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
    wezel->lista = NULL;
    wezel->nazwa = "organizmy";
    wezelPoprz = wezel;

    root = wezel;

    // galaz zwierzat

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->lista = NULL;
    wezel->nazwa = "zwierzeta";
    wezelPoprz->lewy = wezel;
    wezelPoprz = wezel;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->lista = NULL;
    wezel->nazwa = "zyworodne";
    wezelPoprz->lewy = wezel;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->nazwa = "jajorodne";
    wezelPoprz->prawy = wezel;

    // rosliny

    wezelPoprz = root;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->lista = NULL;
    wezel->nazwa = "rosliny";
    wezelPoprz->prawy = wezel;

    wezelPoprz = wezel;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->lista = NULL;
    wezel->nazwa = "nasienne";
    wezelPoprz->prawy = wezel;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->lista = NULL;
    wezel->nazwa = "zarodnikowe";
    wezelPoprz->lewy = wezel;

    wezelPoprz = wezel;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->lista = NULL;
    wezel->nazwa = "paprotniki";
    wezelPoprz->lewy = wezel;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->lista = NULL;
    wezel->nazwa = "mszaki";
    wezelPoprz->prawy = wezel;

    wezelPoprz = wezel;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->lista = NULL;
    wezel->nazwa = "mchy";
    wezelPoprz->lewy = wezel;

    wezel = new Wezel();
    wezel->lewy = NULL;
    wezel->prawy = NULL;
    wezel->lista = NULL;
    wezel->nazwa = "torfowce";
    wezelPoprz->prawy = wezel;

}

void Drzewo::wyswietlDrzewo()
{
    rekurWyswietlDrzewo(root, 0);
}

void Drzewo::wyswietlDrzewo(string nazwaWezla)
{
    Wezel *wezel = rekurDajWezel(root, nazwaWezla);
    if(wezel == NULL)
        cout << "Niepoprawna nazwa wezla " << nazwaWezla << endl;
    else
        rekurWyswietlDrzewo(wezel, 0);
}
void Drzewo::rekurWyswietlDrzewo(Wezel* wezel,int wysokosc)
{

    if(wezel!=NULL)
    {
        wysokosc += 1;
        cout << string(wysokosc*3, ' ') << wezel->nazwa <<
             (jestLisciem(wezel) ? " (lisc)": " ") << endl;
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
    Wezel* wezel = NULL;

    wezel = rekurDajWezel(root, nazwaWezla);
    if(wezel == NULL)
        cout << "Niepoprawna nazwa wezla: " << nazwaWezla << endl;
    else
        aktualny = wezel;

}

Drzewo::Wezel* Drzewo::rekurDajWezel(Wezel *wezel, string nazwaWezla)
{
    Wezel *wezel1 = NULL;
    Wezel *wezel2 = NULL;
    if(wezel != NULL)
    {
        if (nazwaWezla.compare(wezel->nazwa) == 0)
            return wezel;
        else
        {
            wezel1 = rekurDajWezel(wezel->lewy, nazwaWezla);
            wezel2 = rekurDajWezel(wezel->prawy, nazwaWezla);
        }
    }
    return  ((wezel1 != NULL )? wezel1 : wezel2);
}

void Drzewo::usunWszystko()
{
    rekurUsunWszystko(this->root);
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

bool Drzewo::jestLisciem(Wezel* wezel)
{
    if( (wezel->lewy == NULL && wezel->prawy == NULL) )
        return true;
    return false;
}

void Drzewo::dodajDoAktualny()
{
    if(jestLisciem(aktualny) == false)
    {
        cout << "Wezel " << aktualny->nazwa << " nie jest lisciem. "
             << " Operacja niedostepna." << endl;
        return;
    }

    cout << "Opcja niedostepna" << endl;
}

void Drzewo::usunZAktualny(string nazwaObiektu)
{
    if(jestLisciem(aktualny) == false)
    {
        cout << "Wezel " << aktualny->nazwa << " nie jest lisciem. "
             << " Operacja niedostepna." << endl;
        return;
    }

    cout << "Opcja niedostepna" << endl;
}

void Drzewo::wyswietlWszystkieZAltualny()
{
    cout << "Opcja niedostepna" << endl;
}

void Drzewo::wyswietlObiektZAktualny(string nazwaObiektu)
{
    if(jestLisciem(aktualny) == false)
    {
        cout << "Wezel " << aktualny->nazwa << " nie jest lisciem. "
             << " Operacja niedostepna." << endl;
        return;
    }
    cout << "Opcja niedostepna" << endl;

}

Drzewo::OrganizmyZywe Drzewo::dajObiektLisc(string nazwaObiektu)
{
    if (nazwaObiektu.compare("jajorodne"))
    {
        return new Jajorodne();
    }
    else if (nazwaObiektu.compare("zyworodne"))
    {
        return new Zyworodne();
    }
    else if (nazwaObiektu.compare("nasienne"))
    {
        return new Nasienne();
    }
    else if (nazwaObiektu.compare("paprotniki"))
    {
        return new Paprotniki();
    }
    else if (nazwaObiektu.compare("mchy"))
    {
        return new Mchy();
    }
    else if (nazwaObiektu.compare("torfowce"))
    {
        return new Torfowce();
    }
}


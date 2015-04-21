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
    wezel->lista = NULL;
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

void Drzewo::wyswietlWszystkieZWezla()
{
    rekurWyswietlWszystkieZWezla(aktualny, 0);
}

void Drzewo::rekurWyswietlWszystkieZWezla(Wezel* wezel,int wysokosc)
{

    if(wezel!=NULL)
    {
        wysokosc += 1;
        cout << string(wysokosc*3, ' ') << wezel->nazwa <<
             (jestLisciem(wezel) ? " (lisc)": " ") << endl;
        if(jestLisciem(wezel) == true)
        {
            wyswietlWszystkieZWezlaLiscia(wezel);
        }
        rekurWyswietlWszystkieZWezla(wezel->lewy, wysokosc);
        rekurWyswietlWszystkieZWezla(wezel->prawy, wysokosc);
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

void Drzewo::dodajDoAktualny(string nazwa)
{
    if(jestLisciem(aktualny) == false)
    {
        cout << "Wezel " << aktualny->nazwa << " nie jest lisciem. "
             << " Operacja niedostepna." << endl;
        return;
    }

    OrganizmyZywe *orgZy = dajObiektLisc(aktualny->nazwa);
    orgZy->nazwa = nazwa;
    orgZy->edytuj();
    orgZy->nastepny = aktualny->lista;
    aktualny->lista = orgZy;
}

void Drzewo::usunZAktualny(string nazwaObiektu)
{
    if(jestLisciem(aktualny) == false)
    {
        cout << "Wezel " << aktualny->nazwa << " nie jest lisciem. "
             << " Operacja niedostepna." << endl;
        return;
    }

    OrganizmyZywe *orgZy = aktualny->lista;
    OrganizmyZywe *orgZyPo = NULL;
    if(orgZy == NULL)
    {
        cout << "Brak obiektu o nazwie " << nazwaObiektu << endl;
    }
    while(orgZy != NULL)
    {
        if( orgZy->nazwa.compare(nazwaObiektu) == 0)
        {
            if(orgZyPo == NULL)
                aktualny->lista = orgZy->nastepny;
            else
                orgZyPo->nastepny = orgZy->nastepny;
            delete(orgZy);
            return;
        }
        orgZyPo = orgZy;
        orgZy = orgZy->nastepny;
    }
    cout << "Brak obiektu o nazwie " << nazwaObiektu << endl;
}

void Drzewo::edytujZAktualny(string nazwaObiektu)
{
    if(jestLisciem(aktualny) == false)
    {
        cout << "Wezel " << aktualny->nazwa << " nie jest lisciem. "
             << " Operacja niedostepna." << endl;
        return;
    }

    OrganizmyZywe *orgZy = aktualny->lista;
    if(orgZy == NULL)
    {
        cout << "Brak obiektu o nazwie " << nazwaObiektu << endl;
    }
    while(orgZy != NULL)
    {
        if( orgZy->nazwa.compare(nazwaObiektu) == 0)
        {
            orgZy->wyswietlWszy();
            cout << endl << "Wpisz nowe dane: " << endl;
            orgZy->edytuj();
            return;
        }
        orgZy = orgZy->nastepny;
    }
    cout << "Brak obiektu o nazwie " << nazwaObiektu << endl;

}
void Drzewo::wyswietlWszystkieZAltualny()
{
    wyswietlWszystkieZWezlaLiscia(aktualny);
}


void Drzewo::wyswietlWszystkieZWezlaLiscia(Wezel *wezel)
{
    if(jestLisciem(wezel) == false)
    {
        cout << "Wezel " << wezel->nazwa << " nie jest lisciem. "
             << " Operacja niedostepna." << endl;
        return;
    }
    OrganizmyZywe *orgZy = wezel->lista;
    if(orgZy == NULL)
    {
        cout << "Brak elementow do wyswietlenia." << endl;
    }
    while(orgZy != NULL)
    {
        orgZy->wyswietl();
        orgZy = orgZy->nastepny;
    }
}

void Drzewo::wyswietlObiektZAktualny(string nazwaObiektu)
{
    if(jestLisciem(aktualny) == false)
    {
        cout << "Wezel " << aktualny->nazwa << " nie jest lisciem. "
             << " Operacja niedostepna." << endl;
        return;
    }
    OrganizmyZywe *orgZy = aktualny->lista;
    if(orgZy == NULL)
    {
        printf("Brak elementow do wyswietlenia.\n");
    }
    while(orgZy != NULL)
    {
        if( orgZy->nazwa.compare(nazwaObiektu) == 0)
        {
            orgZy->wyswietlWszy();
            return;
        }
        orgZy = orgZy->nastepny;
    }
    cout << "Brak obiektu o nazwie " << nazwaObiektu << endl;
}

OrganizmyZywe* Drzewo::dajObiektLisc(string nazwaObiektu)
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
    else
    {
        printf("Drzewo::dajObiektLisc: Niepoprawna nazwa obiektu.");
        return NULL;
    }
}


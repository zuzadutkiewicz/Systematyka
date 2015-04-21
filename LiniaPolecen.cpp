#include <iostream>
#include <string>

#include "LiniaPolecen.hpp"


void LiniaPolecen::liniaPolecen()
{
    string linia;
    Token *root = NULL;
    int debug = 0;
    while (true)
    {
        cout << drzewo.dajNazwaAktualny() <<  " $ ";
        getline( cin, linia);
        root = dajTokeny(linia.c_str(), root);
        if(debug == 1)
            wyswietlTokeny(root);

        if( czyToPolecenie(root, "exit", 0) )
        {
            return;
        }
        else if( czyToPolecenie(root, "cd", 1) )
        {
            drzewo.ustawAktualnyWezel(string(root->nastepny->opcja));
        }
        else if(czyToPolecenie(root, "cur", 0) )
        {
            cout << drzewo.dajNazwaAktualny() << endl;
        }
        else if(czyToPolecenie(root, "debug", 1))
        {
            if( root->nastepny->opcja.compare("0") == 0 )
                debug = 0;
            else if(root->nastepny->opcja.compare("1") == 0)
                debug = 1;
            else
                cout << "Blad: niepoprawna opcja" << endl;
        }
        else if(czyToPolecenie(root, "tree", 0, 1))
        {
            if(root->nastepny == NULL)
                drzewo.wyswietlDrzewo();
            else
                drzewo.wyswietlDrzewo(string(root->nastepny->opcja));
        }
        else if(czyToPolecenie(root, "dir", 0) )
        {
            drzewo.wyswietlWszystkieZAltualny();
        }
        else if(czyToPolecenie(root, "read", 0) )
        {
            cout << "Opcja niedostepna" << endl;
        }
        else if(czyToPolecenie(root, "save", 0) )
        {
            cout << "Opcja niedostepna" << endl;
        }
        // tworzenie obiektu do aktualnego wezla - mo
        else if(czyToPolecenie(root, "mo", 1) )
        {
            drzewo.dodajDoAktualny();
        }
        // usuwanie obiektu o danej nazwie - do
        else if(czyToPolecenie(root, "do", 1))
        {
            drzewo.usunZAktualny(string(root->nastepny->opcja));
        }
        // modyfikacja obiektu o danej nazwie - mdo
        else if(czyToPolecenie(root, "mdo", 1) )
        {
            cout << "Opcja niedostepna" << endl;
        }
        // wyswietlenie szczegolowych informacji o obiekcie - show
        else if(czyToPolecenie(root, "show", 0, 1) )
        {
            if(root->nastepny == NULL)
                drzewo.wyswietlWszystkieZAltualny();
            else
                drzewo.wyswietlObiektZAktualny(root->nastepny->opcja);
        }
        else if(czyToPolecenie(root, "help", 0) )
                help();
        else
        {
            if(root != NULL )
                cout << "Blad polecenia lub niepoprawne parametry" << endl;
        }
        usunTokeny(root);
        root = NULL;
    }
}

bool LiniaPolecen::czyToPolecenie(Token* root, string polecenie, int opcje)
{
    return czyToPolecenie(root, polecenie, opcje, opcje);
}


bool LiniaPolecen::czyToPolecenie(Token* root, string polecenie, int opcjeMin, int opcjeMax)
{
    if(root != NULL && root->opcja.compare(polecenie) == 0 )
    {
        if( (opcjeMax <= 0 && root->nastepny != NULL) ||
                (opcjeMax <= 1 && root->nastepny != NULL && root->nastepny->nastepny != NULL) ||
                (opcjeMax <= 2 && root->nastepny != NULL && root->nastepny->nastepny != NULL && root->nastepny->nastepny->nastepny != NULL) ||
                (opcjeMax <= 3 && root->nastepny != NULL && root->nastepny->nastepny != NULL && root->nastepny->nastepny->nastepny != NULL && root->nastepny->nastepny->nastepny->nastepny != NULL) )
        {
            cout << "Blad: za duzo parametrow." << endl;
            return false;
        }

        if( ( opcjeMin >= 1 && root->nastepny == NULL) ||
                ( opcjeMin >= 2 && root->nastepny->nastepny == NULL) ||
                ( opcjeMin >= 3 && root->nastepny->nastepny->nastepny == NULL) )
        {
            cout << "Blad: brak parametru." << endl;
            return false;
        }
        return true;
    }
    return false;
}


LiniaPolecen::Token * LiniaPolecen::dajTokeny(string linia, Token *root)
{
    bool nowyToken = true;
    Token *token = NULL;

    for (std::string::iterator it=linia.begin(); it!=linia.end(); ++it)
    {
//        if (isupper(opcja[i]))
        if (isgraph(*it) )
        {
            if (nowyToken == true)
            {
                Token *poprzedni = token;
                token = new Token();
                nowyToken = false;
                token->nastepny = NULL;
                if (root == NULL)
                    root = token;
                else
                    poprzedni->nastepny = token;
            }
            token->opcja = token->opcja + *it;
        }
        else
        {
            nowyToken = true;
        }
    }
    return root;
}

void LiniaPolecen::usunTokeny(Token *root)
{
    Token *nastepny = root;

    while (nastepny != NULL)
    {
        Token *aktualny = nastepny;
        nastepny = aktualny->nastepny;
        delete(aktualny);
    }
}


void LiniaPolecen::wyswietlTokeny(Token *root)
{
    Token *aktualny = root;
    while(aktualny != NULL)
    {
        cout << aktualny->opcja << "->";
        aktualny = aktualny->nastepny;
    }
    cout << "NULL" << endl;
}

void LiniaPolecen::help()
{
    cout << "Dostepne komendy:" << endl;
    cout << "  help - wyswietlenie ta pomocy" << endl;
    cout << "  exit - wyjscie z z programu" << endl;
    cout << "  cd wezel - ustawia \"wezel\" jako biezacy" << endl;
    cout << "  mo obiekt - tworzy \"obiekt\" dla biezacego wezla-liscia" << endl;
    cout << "  do obiekt - usuwa \"obiekt\" dla biezacego wezla-liscia" << endl;
    cout << "  mdo obiekt – modyfikuje \"obiekt\" dla biezacego wezla-liscia" << endl;
    cout << "  show obiekt – wyswietla szczeglowe informacje o \"obiekt\"" << endl;
    cout << "  dir - wyswietla informacje o obiektach widocznych z biezacego poziomu" << endl;
    cout << "  save – zapis zbioru do pliku" << endl;
    cout << "  read – odczyt zbioru z pliku" << endl;
    cout << "  tree [wezel] - wyswietla strukture calego drzewa lub od \"wezel\"" << endl;
    cout << "  cur  - wyswietla aktualny wezel" << endl;
    cout << "  debug [0|1] - wylacza/wlacza tryb debugowania (domyslnie 0) " << endl;
}

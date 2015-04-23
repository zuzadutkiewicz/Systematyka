#include <iostream>
#include <stdio.h>
#include <string.h>

#include "LiniaPolecen.hpp"


void LiniaPolecen::liniaPolecen()
{
    string linia;
    Token *root = NULL;
    while (true)
    {
        cout << drzewo.dajNazwaAktualny() <<  " $ ";
        getline( cin, linia);
        root = dajTokeny(linia.c_str(), root);
        //    wyswietlTokeny(root);
        if(root != NULL && strcmp(root->opcja, "exit") == 0 )
        {
            if(root->nastepny != NULL)
                printf("Blad: za duzo parametrow\n");
            else
                return;
        }
        else if(root != NULL && strcmp(root->opcja, "cd") == 0 )
        {
            if(root->nastepny == NULL)
                printf("Blad: brak parametru\n");
            else if(root->nastepny->nastepny != NULL)
                printf("Blad: za duzo parametrow\n");
            else
            {
                drzewo.ustawAktualnyWezel(string(root->nastepny->opcja));
            }
        }
        else if(root != NULL &&  strcmp(root->opcja, "cur") == 0 )
        {
            if(root->nastepny != NULL)
                printf("Blad: za duzo parametrow\n");
            else
                cout << "Aktualny wezel: " << drzewo.dajNazwaAktualny() << endl;
        }
        else if(root != NULL && strcmp(root->opcja, "tree") == 0 )
        {
            if(root->nastepny != NULL && root->nastepny->nastepny != NULL)
                printf("Blad: za duzo parametrow\n");
            else
                if(root->nastepny == NULL)
                    drzewo.wyswietlDrzewo();
                else
                    drzewo.wyswietlDrzewo(string(root->nastepny->opcja));
        }
        else if(root != NULL && strcmp(root->opcja, "dir") == 0 )
        {
            if(root->nastepny != NULL && root->nastepny->nastepny != NULL)
                printf("Blad: za duzo parametrow\n");
            else
                if(root->nastepny == NULL)
                    drzewo.wyswietlWszystkieZWezla();
                else
                    drzewo.wyswietlWszystkieZWezla(string(root->nastepny->opcja));
        }
        else if(root != NULL && strcmp(root->opcja, "read") == 0 )
        {
            if(root->nastepny != NULL)
                printf("Blad: za duzo parametrow\n");
            else
                cout << "Opcja niedostepna" << endl;
        }
        else if(root != NULL && strcmp(root->opcja, "save") == 0 )
        {
            if(root->nastepny != NULL)
                printf("Blad: za duzo parametrow\n");
            else
                cout << "Opcja niedostepna" << endl;
        }
        // tworzenie obiektu do aktualnego wezla - mo
        else if(root != NULL && strcmp(root->opcja, "mo") == 0 )
        {
            if(root->nastepny == NULL)
                printf("Blad: brak parametru\n");
            else if(root->nastepny->nastepny != NULL)
                printf("Blad: za duzo parametrow\n");
            else
                drzewo.dodajDoAktualny(string(root->nastepny->opcja));
        }
        // usuwanie obiektu o danej nazwie - do
        else if(root != NULL && strcmp(root->opcja, "do") == 0 )
        {
            if(root->nastepny == NULL)
                printf("Blad: brak parametru\n");
            else if(root->nastepny->nastepny != NULL)
                printf("Blad: za duzo parametrow\n");
            else
                drzewo.usunZAktualny(string(root->nastepny->opcja));
        }
        // modyfikacja obiektu o danej nazwie - mdo
        else if(root != NULL && strcmp(root->opcja, "mdo") == 0 )
        {
            if(root->nastepny == NULL)
                printf("Blad: brak parametru\n");
            else if(root->nastepny->nastepny != NULL)
                printf("Blad: za duzo parametrow\n");
            else
                drzewo.edytujZAktualny(string(root->nastepny->opcja));
        }
        // wyswietlenie szczegolowych informacji o obiekcie - show
        else if(root != NULL && strcmp(root->opcja, "show") == 0 )
        {
            if(root->nastepny != NULL && root->nastepny->nastepny != NULL)
                printf("Blad: za duzo parametrow\n");
            else if(root->nastepny == NULL)
                drzewo.wyswietlWszystkieZAltualny();
            else
                drzewo.wyswietlObiektZAktualny(root->nastepny->opcja);
        }
        else if(root != NULL && strcmp(root->opcja, "help") == 0 )
            if(root->nastepny != NULL)
                printf("Blad: za duzo parametrow\n");
            else
                help();

        else
        {
            if(root != NULL )
                printf("Blad: niepoprawna opcja\n");
        }
        usunTokeny(root);
        root = NULL;
    }
}

LiniaPolecen::Token * LiniaPolecen::dajTokeny(const char opcja[], Token *root)
{
    int i = 0;
    int j = -1;
    Token *token = NULL;

    while ((opcja[i] != '\0') && (i <= 200))
    {
//        if (isupper(opcja[i]))
        if (isalpha(opcja[i]) || isdigit(opcja[i]))
        {
            if (j == -1)
            {
                Token *poprzedni = token;
                token = new Token();
                j = 0;
                token->nastepny = NULL;
                if (root == NULL)
                    root = token;
                else
                    poprzedni->nastepny = token;
            }
            token->opcja[j] = tolower(opcja[i]);
            j++;
        }
        else
        {
            if (token != NULL && j != -1)
            {
                token->opcja[j] = '\0';
            }
            j = -1;
        }
        i++;
    }
    if (token != NULL && j != -1)
        token->opcja[j] = '\0';
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
        printf("%s->", aktualny->opcja);
        aktualny = aktualny->nastepny;
    }
    printf("NULL\n");
}

void LiniaPolecen::help()
{
    cout << "Dostepne komendy:" << endl;
    cout << "  help - wyswietlenie ta pomocy" << endl;
    cout << "  exit - wyjscie z z programu" << endl;
    cout << "  cd wezel - ustawia \"wezel\" jako biezacy" << endl;
    cout << "  mo obiekt - tworzy \"obiekt\" dla biezacego wezla-liscia" << endl;
    cout << "  do obiekt - usuwa \"obiekt\" dla biezacego wezla-liscia" << endl;
    cout << "  mdo obiekt - modyfikuje \"obiekt\" dla biezacego wezla-liscia" << endl;
    cout << "  show obiekt - wyswietla szczeglowe informacje o \"obiekt\"" << endl;
    cout << "  dir - wyswietla informacje o obiektach widocznych z biezacego poziomu" << endl;
    cout << "  save - zapis zbioru do pliku" << endl;
    cout << "  read - odczyt zbioru z pliku" << endl;
    cout << "  tree [wezel] - wyswietla strukture calego drzewa lub od \"wezel\"" << endl;
    cout << "  cur  - wyswietla aktualny wezel" << endl;
    //cout << "  debug [0|1] - wylacza/wlacza tryb debugowania (domyslnie 0) " << endl;
}

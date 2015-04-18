#include <iostream>
#include <stdio.h>
#include <string.h>

#include "LiniaPolecen.hpp"


void LiniaPolecen::liniaPolecen()
{
    char opcja [200];
    Token *root = NULL;
    int debug = 0;
    while (true)
    {
        printf("%s $ ", drzewo.dajNazwaAktualny().c_str());
        opcja[0] = '\0';
        scanf("%[^\n]*", opcja);
        getchar();
        root = dajTokeny(opcja, root);
        if(debug == 1)
            wyswietlTokeny(root);
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
        else if(root != NULL && strcmp(root->opcja, "debug") == 0 )
        {
            if(root->nastepny == NULL)
                printf("Blad: brak parametru\n");
            else if( strcmp(root->nastepny->opcja, "0") == 0 )
                debug = 0;
            else if( strcmp(root->nastepny->opcja, "1") == 0)
                debug = 1;
            else
                printf("Blad: niepoprawna opcja\n");
        }
        else if(root != NULL && strcmp(root->opcja, "tree") == 0 )
        {
            if(root->nastepny != NULL)
                printf("Blad: za duzo parametrow\n");
            else
                drzewo.wyswietlDrzewo();
        }
        else
        {
            if(root != NULL )
                printf("Blad: niepoprawna opcja\n");
        }
        usunTokeny(root);
        root = NULL;
    }
}

LiniaPolecen::Token * LiniaPolecen::dajTokeny(char opcja[], Token *root)
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

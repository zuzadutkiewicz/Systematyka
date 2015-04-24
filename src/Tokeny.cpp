
#include <Tokeny.hpp>



Tokeny::Tokeny()
{

}

Tokeny::~Tokeny()
{
    usunTokeny();
}

void Tokeny::wyswietlTokeny()
{
    Token *token = root;
    while(token != NULL)
    {
        cout << token->opcja << "->";
        token = token->nastepny;
    }
    cout << "NULL" << endl;
}

void Tokeny::ustawRoot()
{
    aktualnyToken = root;
}

string Tokeny::dajToken() {

    string retToken;
    if(aktualnyToken == NULL)
        return "";
    else
    {
        retToken = aktualnyToken->opcja;
        aktualnyToken = aktualnyToken->nastepny;
    }

    return retToken;
}

void Tokeny::ustawTokeny(string linia)
{
    bool nowyToken = true;
    Token *token = NULL;
    root = NULL;
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
}


void Tokeny::usunTokeny()
{
    Token *nastepny = root;

    while (nastepny != NULL)
    {
        Token *aktualny = nastepny;
        nastepny = aktualny->nastepny;
        delete(aktualny);
    }
}



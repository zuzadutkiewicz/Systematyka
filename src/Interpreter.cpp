#include "Interpreter.hpp"

Interpreter::Interpreter()
{

}

Interpreter::~Interpreter()
{

}


bool Interpreter::wykonaj(Tokeny* polecenia)
{
        polecenia->ustawRoot();
        string polecenie = polecenia->dajToken();
        if( polecenie.compare("exit") == 0)
        {
            return true;
        }
        else if( polecenie.compare("cd") == 0)
        {
            drzewo.ustawAktualnyWezel(polecenia->dajToken());
        }
        else if(polecenie.compare("cur") == 0)
        {
            cout << drzewo.dajNazwaAktualny() << endl;
        }
        else if(polecenie.compare("tree") == 0)
        {
            string opcja = polecenia->dajToken();
            if(opcja.empty())
                drzewo.wyswietlDrzewo();
            else
                drzewo.wyswietlDrzewo(opcja);
        }
        else if(polecenie.compare("dir") == 0)
        {
            drzewo.wyswietlWszystkieZAltualny();
        }
        else if(polecenie.compare("read") == 0 )
        {
            cout << "Opcja niedostepna" << endl;
        }
        else if(polecenie.compare("save") == 0 )
        {
            cout << "Opcja niedostepna" << endl;
        }
        // tworzenie obiektu do aktualnego wezla - mo
        else if(polecenie.compare("mo") == 0 )
        {
            drzewo.dodajDoAktualny();
        }
        // usuwanie obiektu o danej nazwie - do
        else if(polecenie.compare("do") == 0)
        {
            string opcja = polecenia->dajToken();
            drzewo.usunZAktualny(string(opcja));
        }
        // modyfikacja obiektu o danej nazwie - mdo
        else if(polecenie.compare("mdo") == 0)
        {
            cout << "Opcja niedostepna" << endl;
        }
        // wyswietlenie szczegolowych informacji o obiekcie - show
        else if(polecenie.compare("show") == 0)
        {
            string opcja = polecenia->dajToken();
            if(opcja.empty())
                drzewo.wyswietlWszystkieZAltualny();
            else
                drzewo.wyswietlObiektZAktualny(opcja);
        }
        else if(polecenie.compare("help") == 0)
                help();
        else
        {
            if(polecenie.empty() )
                cout << "Niepoprawne polecenie" << endl;
        }
        return false;
}


string Interpreter::dajNazwaAktualny()
{
    return drzewo.dajNazwaAktualny();
}

void Interpreter::help()
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

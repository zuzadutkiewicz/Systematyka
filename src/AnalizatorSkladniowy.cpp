#include "AnalizatorSkladniowy.hpp"


AnalizatorSkladniowy::AnalizatorSkladniowy( Tokeny* p_tokeny, string p_polecenie)
{
    tokeny = p_tokeny;
    tokeny->ustawTokeny(p_polecenie.c_str());
}

AnalizatorSkladniowy::~AnalizatorSkladniowy()
{

}

Tokeny* AnalizatorSkladniowy::dajTokeny()
{
    return tokeny;
}
bool AnalizatorSkladniowy::analizuj()
{
        tokeny->ustawRoot();
        string komenda = tokeny->dajToken();
        if(komenda.empty())
            return false;
        if( komenda.compare("exit") == 0 ||
            komenda.compare("cur" ) == 0 ||
            komenda.compare("read") == 0 ||
            komenda.compare("save") == 0 ||
            komenda.compare("help") == 0 )
                return sprawdzPolecenie(0, 0);
        else if(komenda.compare("cd" ) == 0 ||
                komenda.compare("mo" ) == 0 ||
                komenda.compare("do" ) == 0 ||
                komenda.compare("mdo") == 0 )
                return sprawdzPolecenie(1, 1);
        else if(komenda.compare("tree" ) == 0 ||
                komenda.compare("show" ) == 0 ||
                komenda.compare("dir" ) == 0 )
                return sprawdzPolecenie(0, 1);
        else
        {
            if(komenda.empty() )
                cout << "Blad polecenia lub niepoprawne parametry" << endl;
        }
        return false;
}


bool AnalizatorSkladniowy::sprawdzPolecenie(int opcjeMin, int opcjeMax)
{
    string opcja1 = tokeny->dajToken();
    string opcja2 = tokeny->dajToken();
    string opcja3 = tokeny->dajToken();
    if( (opcjeMax <= 0 && !opcja1.empty()) ||
            (opcjeMax <= 1 && !opcja1.empty() && !opcja2.empty()) ||
            (opcjeMax <= 2 && !opcja1.empty() && !opcja2.empty() && !opcja3.empty()) )
    {
        cout << "Blad: za duzo parametrow." << endl;
        return false;
    }

    if( ( opcjeMin >= 1 && opcja1.empty())     ||
            ( opcjeMin >= 2 && opcja2.empty()) ||
            ( opcjeMin >= 3 && opcja3.empty()  ) )
    {
        cout << "Blad: brak parametru." << endl;
        return false;
    }
    return true;
}


#include <iostream>
#include <string>

#include "LiniaPolecen.hpp"


void LiniaPolecen::liniaPolecen()
{
    string linia;
    Interpreter interpreter;
    while (true)
    {
        cout << interpreter.dajNazwaAktualny() <<  " $ ";
        getline( cin, linia);
        Tokeny *tokeny = new Tokeny();
        AnalizatorSkladniowy analizator = AnalizatorSkladniowy(tokeny, linia);

        if(analizator.analizuj() == true)
            Tokeny * tokeny = analizator.dajTokeny();
            if(interpreter.wykonaj(tokeny) == true)
                return;

    }
}



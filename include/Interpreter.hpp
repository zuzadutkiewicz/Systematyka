#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <string>
#include <Drzewo.hpp>
#include <Tokeny.hpp>

using namespace std;

class Interpreter
{
    public:
        Interpreter();
        virtual ~Interpreter();
        bool wykonaj(Tokeny* polecenia);
        string dajNazwaAktualny();
    protected:
    private:
        Drzewo drzewo;
        void help();
};

#endif // INTERPRETER_HPP

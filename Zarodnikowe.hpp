#ifndef ZARODNIKOWE_HPP_INCLUDED
#define ZARODNIKOWE_HPP_INCLUDED

#include "Rosliny.hpp"

class Zarodnikowe : public Rosliny
{
public:
    void produkujZarodniki();

private:
    void iloscZarodnikow();
};

#endif // ZARODNIKOWE_HPP_INCLUDED

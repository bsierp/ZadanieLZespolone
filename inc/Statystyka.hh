#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include "BazaTestu.hh"
using std::endl;
using std::cout;
struct Statystyka
{
    int l_poprawnych;
    int l_blednych;
};
void inicjuj(Statystyka & st);
void poprawna(Statystyka & st);
void bledna(Statystyka & st);
int zwrocpop(Statystyka &st);
int zwrocbld(Statystyka & st);
int ileproc(Statystyka & st);
std::ostream & operator<<(std::ostream & strm, Statystyka st);
#endif
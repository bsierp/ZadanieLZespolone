#include "Statystyka.hh"
void inicjuj(Statystyka & st)
{
    st.l_blednych=0;
    st.l_poprawnych=0;
}
void poprawna(Statystyka & st)
{
    st.l_poprawnych++;
}
void bledna(Statystyka & st)
{
    st.l_blednych++;
}
int zwrocpop(Statystyka &st)
{
    return st.l_poprawnych;
}
int zwrocbld(Statystyka & st)
{
    return st.l_blednych;
}
int ileproc(Statystyka & st)
{
    int suma=st.l_blednych+st.l_poprawnych;
    return 100*st.l_poprawnych/suma;
}
std::ostream & operator<<(std::ostream & strm, Statystyka  st)
{
    strm<<"Liczba poprawnych odpowiedzi:"<<zwrocpop(st)<<endl<<"Liczba blednych odpowiedzi:"<<zwrocbld(st)<<endl<<"Procent poprawnych odpowiedzi:"<<ileproc(st)<<'%'<<endl;
}
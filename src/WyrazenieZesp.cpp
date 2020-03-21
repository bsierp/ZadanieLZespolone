#include "WyrazenieZesp.hh"
using std::cout;
using std::endl;
using std::cin;
using std::cerr;
/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
std::istream & operator >>(std::istream & strm,WyrazenieZesp &w)
{
    strm>>w.Arg1>>w.Op>>w.Arg2;
    return strm;
}
std::istream & operator >>(std::istream & strm, Operator &Oper)
{
    char op;
    strm>>op;
    switch (op)
    {
    case '+':
    {
    Oper=Op_Dodaj;
        break;
    }
    case '-':
    {
        Oper=Op_Odejmij;
        break;
    }
    case '*':
    {
        Oper=Op_Mnoz;
        break;
    }
    case '/':
    {
        Oper=Op_Dziel;
        break;
    }
    default:
    {
        cerr<<"Nieprawidlowy operator"<<endl;
        strm.setstate(std::ios::failbit);
     break;
    }
    }
    return strm;
}
std::ostream & operator <<(std::ostream & strm,WyrazenieZesp w)
{
    strm<<w.Arg1<<w.Op<<w.Arg2;
    return strm;
}
std::ostream & operator <<(std::ostream & strm,Operator Oper)
{
    switch (Oper)
    {
    case Op_Dodaj:
    {
        strm<<'+';
        break;
    }
    case Op_Odejmij:
    {
        strm<<'-';
        break;
    }
    case Op_Mnoz:
    {
        strm<<'*';
        break;
    }
    case Op_Dziel:
    {
        strm<<'/';
        break;
    }
    default:
        break;
    }
    return strm;
}
LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
    LZespolona Wynik;
switch (WyrZ.Op)
{
case Op_Dodaj:
{
 Wynik=WyrZ.Arg1+WyrZ.Arg2;
 
    break;
}
case Op_Odejmij:
{
   Wynik=WyrZ.Arg1-WyrZ.Arg2;
   
    break;
}
case Op_Dziel:
{
    Wynik=WyrZ.Arg1/WyrZ.Arg2;
    
    break;
}
case Op_Mnoz:
{
    Wynik=WyrZ.Arg1*WyrZ.Arg2;
    
    break;
}
}
return Wynik;
}
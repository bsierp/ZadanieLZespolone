#include "WyrazenieZesp.hh"
using std::cout;
using std::endl;
using std::cin;
using std::cerr;
/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
bool Wczytaj(WyrazenieZesp &WyrZ){
    char op;
    if(wczytaj(WyrZ.Arg1)==true)
    {
    cin>>op;
    switch (op)
    {
    case '+':
    {
       WyrZ.Op=Op_Dodaj;
        break;
    }
    case '-':
    {
        WyrZ.Op=Op_Odejmij;
        break;
    }
    case '*':
    {
        WyrZ.Op=Op_Mnoz;
        break;
    }
    case '/':
    {
        WyrZ.Op=Op_Dziel;
        break;
    }
    default:
    {
        cerr<<"Nie rozpoznano operatora"<<endl;
        return false;
        break;
    }
        break;
    }
    if(wczytaj(WyrZ.Arg2)==true)
    return true;
    else
    {
    cerr<<"Wyrazenie nie zostalo wczytane poprawnie"<<endl;
    return false;  
    }
    }
else
{
    cerr<<"Wyrazenie nie zostalo wczytane poprawnie"<<endl;
    return false;
}

}
void Wyswietl(WyrazenieZesp  WyrZ){
wyswietlaj(WyrZ.Arg1); 
switch (WyrZ.Op)
{
case Op_Dodaj:
   {
       cout<<'+';
    break;
   }
   case Op_Mnoz:
   {
       cout<<'*';
       break;
   }
   case Op_Odejmij:
   {
       cout<<'-';
       break;
   }
   case Op_Dziel:
   {
       cout<<'/';
       break;
   }
default:
    break;
}
wyswietlaj(WyrZ.Arg2);
cout<<endl;
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
#include "LZespolona.hh"
using std::cout;
using std::showpos;
using std::noshowpos;
using std::endl;
using std::cin;
/*
Realizuje operacje modulu liczby zespolonej
Argument:
Skl1 - liczba, ktora ma zostac poddana modulowi
Zwraca:
Liczbe rzeczywista bedaca modulem liczby zespolonej
*/
double modul(LZespolona Skl1)
{
  double Wynik;
  Wynik=sqrt(Skl1.re*Skl1.re+Skl1.im*Skl1.im);
  return Wynik;
}
/*
Sprzezenie liczby zespolonej
Argument:
Skl1-Liczba do sprzezenia
Zwraca:
Sprzezona liczbe zespolona
*/
LZespolona Sprzez(LZespolona Skl1){
  LZespolona Wynik;
  Wynik.re=Skl1.re;
  Wynik.im=-Skl1.im;
  return Wynik;
}
/*
Dzielenie liczby zespolonej przez liczbe rzeczywista
Argumenty:
Skl1-Liczba zespolona do podzielenia
Skl2-Dzielnik liczby zespolonej
Zwraca:
Liczbe zespolona podzielona przez rzeczywista
*/

LZespolona operator / (LZespolona Skl1,double Skl2 )
{
LZespolona Wynik;
Wynik.re = Skl1.re/Skl2;
Wynik.im = Skl1.im/Skl2;
return Wynik;
}
/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
/*
Realizuje odejmowanie dwoch liczb zespolonych
Argumenty:
Skl1 - Liczba od ktorej zostanie odjeta druga
Skl2 - liczba ktora bedzie odejmowana
Zwraca:
Roznice liczb przekazanych jako parametry
*/
LZespolona operator - (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}
/*
Realizuje mnozenie liczb zespolonych
Argumenty:
Skl1 - Pierwszy czynnik mnozenia
Skl2 - Drugi skladnik mnozenia
Zwraca:
Iloczyn liczb przekazanych jako parametry
*/
LZespolona operator * (LZespolona Skl1, LZespolona Skl2)
{
LZespolona Wynik;

Wynik.re = Skl1.re*Skl2.re-Skl1.im*Skl2.im;
Wynik.im = Skl1.re*Skl2.im+Skl1.im*Skl2.re;
return Wynik;
}
/*
Realizuje dzielenie liczb zespolonych
Argumenty:
Skl1 - liczba do podzielenia 
Skl2 - dzielnik
Zwraca:
Podzielony parametr pierwszy przez drugi
*/
LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;
  Wynik=(Skl1*Sprzez(Skl2))/(modul(Skl2)*modul(Skl2));
  return Wynik;
  }
/*
Tworzy liczbe zespolona
Argumenty:
r - czesc rzeczywista liczby zespolonej
i - czesc urojona liczby zespolonej
Zwraca:
Liczbe zespolona utworzona z przekazanych parametrow
*/
LZespolona utworz(double r, double i){
  LZespolona l;
  l.re=r;
  l.im=i;
  return l;
}
/*
Wyswietla liczbe zespolona
Argument:
l - liczba do wyswietlenia
*/


std::istream & operator >>(std::istream & strm, LZespolona & l)
{
  char znak;
  strm>>znak;
  if(znak!='(')
  strm.setstate(std::ios::failbit);
  strm>>l.re>>l.im>>znak;
  if(znak!='i')
  strm.setstate(std::ios::failbit);
  strm>>znak;
  if(znak!=')')
  strm.setstate(std::ios::failbit);
  return strm;
}
std::ostream & operator <<(std::ostream & strm, LZespolona l)
{
  strm<<'('<<l.re<<showpos<<l.im<<noshowpos<<"i)";
}
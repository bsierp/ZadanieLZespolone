#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include<iostream>
#include<cmath>
#include<cstring>
/*
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator - (LZespolona Skl1, LZespolona Skl2);
LZespolona operator * (LZespolona Skl1, LZespolona Skl2);
LZespolona operator / (LZespolona Skl1, LZespolona Skl2);
LZespolona operator / (LZespolona Skl1,double Skl2 );
LZespolona Sprzez(LZespolona Skl1);
double modul(LZespolona Skl1);
LZespolona utworz(double r, double i);
void wyswietlaj(LZespolona l);
bool wczytaj(LZespolona &l);
#endif

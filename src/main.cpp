#include <iostream>
#include "Statystyka.hh"
using std::cout;
using std::endl;
using std::cin;
using std::cerr;





int main(int argc, char **argv)
{
  
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  int a;
  LZespolona Odp;
  Statystyka wynik;
  inicjuj(wynik);
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    a=0;
    while(a!=3){
    cout << "Rozwiaz podane wyrazenie:" ;
    cout << WyrZ_PytanieTestowe << endl;
    cin >> Odp;
    if(!cin.good()){
      cin.clear();
      cin.ignore(10000,'\n');
      if(a!=3)
      cout<<"Niepoprawny format odpowiedzi. Pozostalo prob:"<<3-++a<<endl;
      if(a==3){
      cout<<"Wykorzystano limit blednych prob. Odpowiedz uznana za bledna."<<endl;
      cout<<"Prawidlowa odpowiedz to:"<<Oblicz(WyrZ_PytanieTestowe)<<endl;
      bledna(wynik);
      }
    }
    else{
    if(Odp==Oblicz(WyrZ_PytanieTestowe)){
      cout<<"Gratulacje! Poprawna odpowiedz.Przejdz do nastepnego pytania"<<endl;
      poprawna(wynik);
    }
    else
    {
      cout<<"Odpowiedz niepoprawna.Prawidlowa odpowiedz to:"<<Oblicz(WyrZ_PytanieTestowe)<<"Przejdz do nastepnego pytania"<<endl;
      bledna(wynik);
    }  
    a=3;
    }
    }
    }
  cout << endl;
  cout << " Koniec testu" << endl;
  cout <<wynik;
  cout << endl;

}


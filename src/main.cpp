#include <iostream>
#include "BazaTestu.hh"

using namespace std;




int main(int argc, char **argv)
{
  int a=1;
  LZespolona l1,l2,l3;
  WyrazenieZesp wyr;
    l1=utworz(2,3);
    l2=utworz(2,-4);
    l3=l1/l2;
   cin>>wyr;
   if(!cin.good())
   cin.clear();
   else
   cout<<wyr<<endl;
  if(a!=1){
  if (argc > 2) {
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
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " Czesc rzeczywista pierwszego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg1.re << endl;
  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
}

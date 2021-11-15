#include <iostream>
using namespace std;
main()
{
  int num1;                
  num1 = 0;                
  cout << "\nInserisci un numero > 2 : ";  
  cin  >> num1;
  while (num1 > 1)    // condizione di entrata  
    num1 = num1 - 2;  // corpo del ciclo  
  if (num1 == 0)   
    cout << "\nil numero e' pari";
  else
    cout << "\nil numero e' dispari";

 printf("\n\n");
}





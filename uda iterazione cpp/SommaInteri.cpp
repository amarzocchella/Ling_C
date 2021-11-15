#include <iostream>
using namespace std;
main()
{
  int tanti, num1, conta, totale;
  do                       // ciclo di controllo input
  {                        // compresa tra 3 e 10
    cout << "Inserisci un numero 3 < N < 10: ";
    cin  >> tanti ;
  }while ((tanti < 3)||(tanti > 10));
 
  conta  = 0;                    // contatore
  totale = 0;                    // accumulatore
  do 
  {
    cout << "inserisci un numero : ";
    cin  >> num1 ;
    conta = conta + 1;          // incremento il contatore
    totale = totale + num1;     // aggiorno il totale
  }while (conta < tanti);       // condizione di uscita  
  cout << "\nla somma e\': " << totale;
  cout << "\nla media e\': " << totale/conta;

  printf("\n\n");
}

#include <iostream>
#include <stdlib.h>    // srand, rand 
#include <time.h>      // time 
using namespace std;
main()
{
  int tanti, numero, conta, totPari, totDispari, contaPari, contaDispari;
  do                      
  {                        // compresa tra 10 e 20
    cout << "Inserisci un numero 10 < N < 20: ";
    cin  >> tanti ;
  }while ((tanti < 10)||(tanti > 20));
 
  contaPari  = 0;                   
  contaDispari  = 0;                   
  totPari  = 0;                   
  totDispari  = 0;                   
  srand (time (NULL));                // inizializzo il seme

  do 
  {
    numero = (rand () % 100) + 101;   // numero tra 100 e 200
 	conta = conta + 1;                // incremento il contatore
     if ( conta % 2 == 0 ){
      contaPari++;
      totPari+=numero;
    }else{
      contaDispari++;
      totDispari+=numero;
    }
   
  }while (conta < tanti);            // condizione di uscita  
  cout << "\ni pari sono : " << contaPari;
  cout << "\nla media e\'  : " << totPari/contaPari;
  cout << "\ni dispari sono : " << contaDispari;
  cout << "\nla media e\'    : " << totDispari/contaDispari;

  printf("\n\n");
}

#include "stdafx.h"         // libreria standard 

#include <iostream>
using namespace std;
int main()
{
  int fuori, dentro; 
  for(fuori = 1; fuori <= 6; fuori++)       
  { 
    cout << "\n";                    
    for(dentro = 1; dentro <= 6; dentro++)  
      cout << " \t" << fuori*dentro;    
  }    
}




#include "Ports.h"

int main() 
{
  char c;
  while(1) 
  {
    // L�s inport
    c = ML4READ;
 
    // Skriv till utport
    ML4WRITE = c;
  
  }
  
  return 0;
}
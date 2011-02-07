#include "Ports.h"

int main() 
{
  char c;
  while(1) 
  {
    // Läs inport
    c = ML4READ;
 
    // Skriv till utport
    ML4WRITE = c;
  
  }
  
  return 0;
}
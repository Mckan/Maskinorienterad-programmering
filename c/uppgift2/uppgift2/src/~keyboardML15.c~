#include "keyboardML15.h"
#include "ports.h"

void main(void) {
  
  while(1)
    ML4WRITE = ML15_Keyboard();
  
  
}



unsigned char ML15_Keyboard(void)
{
  unsigned char key;
  unsigned char k;

  int keyIsSet = 0;
  
  while(1)
  {
    k = KEYBOARD;
    // Om bit 7 är 0a => tangent nere => läs
    while(k < 128)
    {
      // Om key inte är satt, sätt den
      if(keyIsSet == 0) 
      {
        // Key blir då indexet från KEYBOARD i keytab eftersom alla andra bitar är 0a
        key = keytab[k];
        keyIsSet = 1;
      }
      k = KEYBOARD;
    }
    if(keyIsSet == 1)
      break;
  }
  return key;
  
}

#include "keyboardML15.h"
#include "ports.h"

unsigned char keytab[] = {0,4,8,12,1,5,9,13,2,6,10,14,3,7,11,15};

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
      // Läs inport igen för att testa bit 7
      k = KEYBOARD;
    }
    if(keyIsSet == 1)
      break;
  }
  return key;
}

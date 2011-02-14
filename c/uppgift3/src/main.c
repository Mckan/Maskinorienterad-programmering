#include "init.h"
#include "keyboardML15.h"
#include "tools.h"
#include "ports.h"
#include "actions.h"

void main(void)
{
  init();
  while(1)
  {
	  // Initiera vars
	  
	  comnr = ML15_Keyboard();
	  switch(comnr) 
	  {
	     // Starta borren
	     case 0:
	       start();
	       break;
	       
	     // Stoppa borren
	     case 1:
	       stop();
	       break;
	       
	     // S�nk borren
	     case 2:
	       down();
	       break;
	       
	     // H�j borren
	     case 3:
	       up();
	       break;
	       
	     // Stega
	     case 4:
	       step();
	       break;
	       
	     // Borra
	     case 5:
	       break;
	       
	     //Auto 
	     case 6:
	       break;
	       
	     // Om fel v�rde
	     default:
	       break;
	  
	  }


}

}


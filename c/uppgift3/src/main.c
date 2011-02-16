#include "init.h"
#include "keyboardML15.h"
#include "tools.h"
#include "ports.h"
#include "actions.h"

void main(void)
{ 
  // Init program
  init();
  irqinit();
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
	       drill();
	       break;
	       
	     //Auto 
	     case 6:
	       auto_drill();
	       break;
	       
	     // Om fel v�rde
	     default:
	       break;
	  
	  }

  }
}



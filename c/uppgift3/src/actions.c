#include "actions.h"
#include "tools.h"
#include "init.h"
#include "ports.h"

void start()
{
  // Etta till bit 2 startar borren
  outone(2);
  
  // Vänta i 200ms  
  delay(40);
}

void stop()
{
  // Nolla till bit 2 stannar borren
  outzero(2); 
}

void down()
{
  // Är borren startad? Kolla bit 2!
  if(drcopy & 4)
  {
    // Etta på bit 3 sänker borren
    outone(3);
  }
}

void up()
{
  unsigned char status;
  // Är borren nere? Kolla bit 2!
  if(drcopy & 8)
  {
    // Nolla på bit 3 sänker borren
    outzero(3);
  }
  
  // Läs status
  status = DRSTATUS;
  // Medans status ej är "borr i topp", vänta
  while(!(status & 2))
  {
    // Borr i topp, break;
    status = DRSTATUS;
  }
}

void step()
{

  unsigned char status = DRSTATUS;
  if(status & 2)
  {
    // Ettställ riktningsbiten 
    outone(1);
    
    // Ettställ stegpuls biten
    outone(0);
    
    // Nollställ stegpulsbiten för att göra klar pulsen
    delay(10);
    outzero(0);
  }
  else
  {
    // Ge alarm
    alarm(2);
  }
  
}


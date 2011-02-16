#include "actions.h"
#include "tools.h"
#include "init.h"
#include "ports.h"

unsigned char pattern[] = {0,1,1,1,1,1,1,1,2,1,5,2,2,2,2,4,4,3,8,2,0xFF};

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
void drill()
{
  start();
  down();
  ddtest();
  up();
  stop();
}


void auto_drill()
{
  unsigned char i = 0;
  // Gå till referensposition
  refpo();
  
  // Så länge det inte är slutmarkering
  while(pattern[i] != 0xFF)
  {
    // Stega antal steg och borra ett hål
    nstep(pattern[i]);
    drill();
    i++;
  }
  
}

#include "actions.h"
#include "tools.h"
#include "init.h"
#include "ports.h"

unsigned char pattern[] = {0,1,1,1,1,1,1,1,2,1,5,2,2,2,2,4,4,3,8,2,0xFF};

void start()
{
  // Etta till bit 2 startar borren
  outone(2);
  
  // V�nta i 200ms  
  delay(40);
}

void stop()
{
  // Nolla till bit 2 stannar borren
  outzero(2); 
}

void down()
{
  // �r borren startad? Kolla bit 2!
  if(drcopy & 4)
  {
    // Etta p� bit 3 s�nker borren
    outone(3);
  }
}

void up()
{
  unsigned char status;
  // �r borren nere? Kolla bit 2!
  if(drcopy & 8)
  {
    // Nolla p� bit 3 s�nker borren
    outzero(3);
  }
  
  // L�s status
  status = DRSTATUS;
  // Medans status ej �r "borr i topp", v�nta
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
    // Ettst�ll riktningsbiten 
    outone(1);
    
    // Ettst�ll stegpuls biten
    outone(0);
    
    // Nollst�ll stegpulsbiten f�r att g�ra klar pulsen
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
  // G� till referensposition
  refpo();
  
  // S� l�nge det inte �r slutmarkering
  while(pattern[i] != 0xFF)
  {
    // Stega antal steg och borra ett h�l
    nstep(pattern[i]);
    drill();
    i++;
  }
  
}

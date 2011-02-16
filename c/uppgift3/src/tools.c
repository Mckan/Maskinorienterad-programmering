#include <time.h>
#include "ports.h"
#include "tools.h"
#include "init.h"

unsigned char bitpattern_1[] = {0x1,0x2,0x4,0x8,0x10,0x20,0x30,0x40};
unsigned char bitpattern_0[] = {0xFE,0xFC,0xFB,0xF7,0xEF,0xCF,0xBF,0x7F};

void outone(unsigned char bit)
{
  // Ettst�ll bitnr bit p� utporten
  drcopy = drcopy | bitpattern_1[bit];
  DRCTRL = drcopy;
}

void outzero(unsigned char bit)
{
  // Nollst�ll bitnr bit p� utporten
  drcopy = drcopy & bitpattern_0[bit];
  DRCTRL = drcopy;
}


void delay(unsigned char k)
{
  unsigned int i = 0;
  //unsigned int j = 20000 * k; IRL
  unsigned int j = 50 * k; // ISL
  for (i; i < j; i++)
  {
    __asm(" NOP");
    __asm(" NOP");
    __asm(" NOP");
    __asm(" NOP");
    __asm(" NOP");
    __asm(" NOP");
  }
}

void alarm(unsigned char signals)
{
  unsigned char i = 0;
  while(i < signals)
  {
    outone(4);
    delay(8);
    outzero(4);
    delay(4);
    i++;
  }
}

void ddtest()
{
   unsigned char status;
   unsigned char count;
   
   status = DRSTATUS;
   while(!(status & 4))
   {
      // F�rdr�j testet om borr nere
      delay(2);
      
      // �ka r�knare 
      count++;
      
      // Om det g�tt 4 sek (count=40) skicka alarm och hoppa ut
      if(count == 40)
      {
        alarm(2);
	break;
      }
      // L�s status igen
      status = DRSTATUS;
   }
}
void refpo()
{
  // L�s status
  unsigned char status = DRSTATUS;
  
  // Kolla bit 0 om den �r 1a
  while(!(status & 1))
  {
    // Inte 1a, stega och l�s igen
    step();
    status = DRSTATUS;
  }
}

void nstep(unsigned char steps)
{
  // S�tt r�knare
  char i = 0;
  // Medans i �r mindre �n antalet steg in
  while(i < steps)
  {
    // Stega och �ka i
    step();
    i++;
  }
}





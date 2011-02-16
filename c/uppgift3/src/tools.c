#include <time.h>
#include "ports.h"
#include "tools.h"
#include "init.h"

unsigned char bitpattern_1[] = {0x1,0x2,0x4,0x8,0x10,0x20,0x30,0x40};
unsigned char bitpattern_0[] = {0xFE,0xFC,0xFB,0xF7,0xEF,0xCF,0xBF,0x7F};

void outone(unsigned char bit)
{
  // Ettställ bitnr bit på utporten
  drcopy = drcopy | bitpattern_1[bit];
  DRCTRL = drcopy;
}

void outzero(unsigned char bit)
{
  // Nollställ bitnr bit på utporten
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
      // Fördröj testet om borr nere
      delay(2);
      
      // Öka räknare 
      count++;
      
      // Om det gått 4 sek (count=40) skicka alarm och hoppa ut
      if(count == 40)
      {
        alarm(2);
	break;
      }
      // Läs status igen
      status = DRSTATUS;
   }
}
void refpo()
{
  // Läs status
  unsigned char status = DRSTATUS;
  
  // Kolla bit 0 om den är 1a
  while(!(status & 1))
  {
    // Inte 1a, stega och läs igen
    step();
    status = DRSTATUS;
  }
}

void nstep(unsigned char steps)
{
  // Sätt räknare
  char i = 0;
  // Medans i är mindre än antalet steg in
  while(i < steps)
  {
    // Stega och öka i
    step();
    i++;
  }
}





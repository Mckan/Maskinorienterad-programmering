#include "init.h"
#include "ports.h"

__interrupt void IRQHandler(void);

unsigned char comnr;
unsigned char drcopy;


void init()
{
   comnr = 0;
   drcopy = 0;

}

void irqinit()
{
  // Sätt avbrottsvektor
  *(unsigned short *) 0xFFF2 = (unsigned short) IRQHandler; // ISL
  //*(unsigned short *) 0x3FF2 = (unsigned short) IRQHandler; // IRL
  
  // Nollställ vippor genom skrivning
  IRES1 = 0xFF;
  IRES2 = 0xFF;
  
  __asm(" CLI");
}

void givealarm()
{
  alarm(1);
}
__interrupt void IRQHandler(void)
{
  // Läs IRQ status
  unsigned char status = IRQSRC;
  // Om bit 0 är etta
  if(status & 1)
  {
    // Skriv till vippan för att nollställa den
    IRES1 = 0xFF;
    
    // Hoppa tillbaka till main()
    __asm(" JMP __start");
  }
  // Bit 0 är 0a, antar att bit 1 är 1a
  else
  {
    unsigned char i = 1;
    // Ge signal
    alarm(i);
    
    // Skriv till vippan för att nollställa den 
    IRES2 = 0xFF;
    
    // Nollställ I-flaggan
    __asm(" CLI");
        
  }
}




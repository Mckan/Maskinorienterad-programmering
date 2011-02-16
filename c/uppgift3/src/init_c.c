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
  // S�tt avbrottsvektor
  *(unsigned short *) 0xFFF2 = (unsigned short) IRQHandler; // ISL
  //*(unsigned short *) 0x3FF2 = (unsigned short) IRQHandler; // IRL
  
  // Nollst�ll vippor genom skrivning
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
  // L�s IRQ status
  unsigned char status = IRQSRC;
  // Om bit 0 �r etta
  if(status & 1)
  {
    // Skriv till vippan f�r att nollst�lla den
    IRES1 = 0xFF;
    
    // Hoppa tillbaka till main()
    __asm(" JMP __start");
  }
  // Bit 0 �r 0a, antar att bit 1 �r 1a
  else
  {
    unsigned char i = 1;
    // Ge signal
    alarm(i);
    
    // Skriv till vippan f�r att nollst�lla den 
    IRES2 = 0xFF;
    
    // Nollst�ll I-flaggan
    __asm(" CLI");
        
  }
}




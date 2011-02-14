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
/**
clra - 1 * 1
clrb - 1 * 1
std - 1 * 2
ldd - k * 2
cpd - k * 2
bcc - k * 1
ldx - k * 3
inx - k * 1
stx - k * 2
bra - k * 3
leas - 1 * 2
rts 1 * 5

125ns * 40 = 5mikros
5 mikros * 10000 = 50ms

Snittiden för k*klockcykel ger 2.851...
*/

  //float i = 2.85714285714 * k * 1; // Borde vara 10000 inte 1
  unsigned int i = 100 * k;
  unsigned int j = 0;
  for (j; j < i; j++);

}

void alarm(unsigned char signals)
{
  int i;
  for(i = 0; i < signals; i++)
  {
    outone(4);
    delay(8);
    outzero(4);
    delay(4);
  }
}

unsigned int check_bit_set(unsigned char bit)
{
  unsigned char status;
  unsigned int r = 0;
  // Läs status
  status = DRSTATUS;
  // Medans status ej är "borr i topp", vänta
  while(!(status & bit))
  {
    r = 1;
    // Borr i topp, break;
    status = DRSTATUS;
  }
  
  return r;
}

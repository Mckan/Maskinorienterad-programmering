#ifndef FILE_PORTS_H
#define FILE_PORTS_H

#define ML4OUT 0x400

#define ML4STAT 0x401 // ISL
//#define ML4STAT 0x600 // IRL

#define ML15IN 0x9C0
#define IRQIN 0xDC0
#define IRQ1 0xDC2
#define IRQ2 0xDC3


#define DRCTRL *((unsigned char *) ML4OUT)
#define DRSTATUS *((unsigned char *) ML4STAT)
#define KEYBOARD *((unsigned char *) ML15IN)
#define IRQSRC *((unsigned char *) IRQIN)
#define IRES1 *((unsigned char *) IRQ1)
#define IRES2 *((unsigned char *) IRQ2)

#endif

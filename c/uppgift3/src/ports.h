#ifndef FILE_PORTS_H
#define FILE_PORTS_H

#define ML4OUT 0x400
#define ML4STAT 0x401
#define ML15IN 0x9C0

#define DRCTRL *((unsigned char *) ML4OUT)
#define DRSTATUS *((unsigned char *) ML4STAT)
#define KEYBOARD *((unsigned char *) ML15IN)
#endif

#ifndef FILE_TOOLS_H
#define FILE_TOOLS_H
void outone(unsigned char bit);
void outzero(unsigned char bit);
void delay(unsigned char arg0);
void alarm(unsigned char signals);

void ddtest();
void nstep(unsigned char steps);
void refpo();

unsigned int check_bit_set(unsigned char bit);

#endif

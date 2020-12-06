#include<stdio.h>

void fileRead(const char *filePath,char *buffer);
static void editfile(Byte * fn);
static Byte *new_screen(int ro, int co);

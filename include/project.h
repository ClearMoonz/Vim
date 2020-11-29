#include<stdio.h>

void fileRead(const char *filePath,char *buffer);
static void edit_file(Byte * fn);
static Byte *new_screen(int ro, int co);

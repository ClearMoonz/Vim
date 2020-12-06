#include<stdio.h>
#include<stdlib.h>
static void editfile(const char *fn)
{
    char ch;
    FILE *fp=fopen(fn,a+);
    if(fn==NULL){
	    printf("failed\n");
	}
    ch=getchar();
    while(ch!=EOF)
    {
        fputs(ch,fn);
    }
}
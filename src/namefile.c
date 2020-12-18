#include<stdio.h>
#include <fcntl.h>
int main(void)
{
    char oldname[100],newname[100];
    printf("oldname:");
    gets(oldname);
    printf("newname:");
    gets(newname);
    if(rename(oldname,newname)==0)  printf("changed%sto%s.\n",oldname,newname);
    else printf("failed");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc,char *argv[])
{
DIR *directory_pointer;
struct dirent *entry;
struct FileList
{
char filename[64];
struct FileList *next;
}start,*node;

char dir[80];
puts( "Please input the directory: ");
gets(dir);
if ((directory_pointer=opendir(dir))==NULL)
printf( "Error opening %s\n ",dir);
else
{
start.next=NULL;
node=&start;
while ((entry=readdir(directory_pointer))!=NULL)
{
node-> next=(struct FileList *)malloc(sizeof(struct FileList));
node=node-> next;
strcpy(node-> filename,entry-> d_name);
node-> next=NULL;
}
closedir(directory_pointer);
node=start.next;
while(node)
{
printf( "%s\n ",node-> filename);
node=node-> next;
}
}
system( "PAUSE ");
return 0;
}
#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
typedef unsigned char Byte;
void readFile(const char *filePath,char *buffer){
	FILE*fp=fopen(filePath,"r");
	if(filePath==NULL){
	    printf("file doesn't exist\n");
	}else {
        
	}	
}
int tree(char dir[])
{
DIR *directory_pointer;
struct dirent *entry;
struct FileList
{
char filename[64];
struct FileList *next;
}start,*node;
int i=-1;
char *pp[100];

if ((directory_pointer=opendir(dir))==NULL)
printf( "Error opening %s\n ",dir);
else
{
start.next=NULL;
node=&start;
while ((entry=readdir(directory_pointer))!=NULL)
{
	i++;
node-> next=(struct FileList *)malloc(sizeof(struct FileList));

pp[i]=(char*)malloc(64*sizeof(char));
pp[i]=&entry-> d_name;
node=node-> next;
strcpy(node-> filename,entry-> d_name);
node-> next=NULL;
}
closedir(directory_pointer);
node=start.next;
i=-1;
while(node)
{
printf( "%s\n ",node-> filename);
node=node-> next;
}
}
return pp;
}	
HANDLE hout;
char get_input(void);
void TextAttribute ()
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);    /* 获取标注输出句柄 */
    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE); /* 设置控制台颜色，前景色为蓝色*/
    SetConsoleTextAttribute(hOut, BACKGROUND_RED);    /* 背景色为红色 */
}
void TextAttributeback ()
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);    
    SetConsoleTextAttribute(hOut, 7); 
    SetConsoleTextAttribute(hOut, 0);    
}
int move(char *ppp[])
{
    int i=0;
    char ch;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    while (1)
    {
        ch = get_input();
		if(ch == 0x50) i--;
		if(ch == 0x4d) i++;
        if(ch==0x0d) {
            printf("\r");
			void TextAttribute ();
            
			void TextAttributeback ();
            break;
            break;}
        printf("%c",ch);
    }
}
char get_input(void)
{
    int ch;
    COORD coord;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    coord.X = 10;
    coord.Y = 10;
    ch = _getch();
    while (ch == 0XE0 || ch == 0X0D)
    {
        GetConsoleScreenBufferInfo(hout, &csbi);
        coord.X = csbi.dwCursorPosition.X;
        coord.Y = csbi.dwCursorPosition.Y;
        ch = _getch();
        if (ch == 0x48)
        {
            if (coord.Y != 0)
                coord.Y--;
        }
        else if (ch == 0x50)
        {
            coord.Y++;
        }
        else if (ch == 0x4b)
        {
            if (coord.X != 0)
                coord.X--;
        }
        else if(ch == 0x4d)
        {
            if (coord.X != 79)
                coord.X++;
            else
            {
                coord.X = 0;
                coord.Y++;
            }
        }
        SetConsoleCursorPosition(hout, coord);
        ch = _getch();
    }
    return ch;
}
int main()
{
	char dir[80];
	char **ppp;
	printf("the filepath:");
	gets(dir);
	ppp=tree(dir);
	move(ppp);
	return 0;
}
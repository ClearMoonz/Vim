#include<stdio.h>
#include<conio.h>
int main(void)
{
/*clearthescreen*/
clrscr();
/*createatextwindow*/
window(10,10,80,25);
/*outputsometextinthewindow*/
cprintf("Helloworld\r\n");
/*waitforakey*/
getch();
return0;
}
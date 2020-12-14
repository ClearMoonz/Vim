#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
 
#define MAXNAME 200
void s_printf(char *filename,int depth);
void s_dirwalk(char *dirname,int depth,void (*fcn)(char *,int));
void listdirtree(char *dirname,int depth);
 
int main(int argc,char **argv)
{
    if(argc == 1)
        listdirtree(".",0);
    else
    {
        printf("%s\n",argv[1]);
        listdirtree(*++argv,0);
    }
    return 0;
}
 
void listdirtree(char *dirname,int depth)
{
    struct stat stbuf;
    if((stat(dirname,&stbuf)) == -1)
    {
        fprintf(stderr,"listdirtree:can't read file %s information!\n",dirname);
        return;
    }
    if((stbuf.st_mode & S_IFMT) == S_IFDIR)
        s_dirwalk(dirname,depth,listdirtree);
}
 
void s_dirwalk(char *dirname,int depth,void (*fcn)(char *,int))
{
    char name[MAXNAME];
    struct dirent *fip;
    DIR *dp;
    if((dp = opendir(dirname)) == NULL)
    {
        fprintf(stderr,"s_dirwalk:can't open %s\n",dirname);
        return;
    }
    while((fip = readdir(dp)) != NULL)
    {
        if(strcmp(fip->d_name,".") == 0 || strcmp(fip->d_name,"..") == 0)/*skip directory '.' and '..'*/
            continue;
        if(strlen(dirname) + strlen(fip->d_name) + 2 > sizeof(name))
        {
            fprintf(stderr,"s_dirwalk:%s/%s is too long!\n",dirname,fip->d_name);
            return;
        }
        else
        {
            s_printf(fip->d_name,depth);
            sprintf(name,"%s/%s",dirname,fip->d_name);
            (*fcn)(name,depth + 1);
        }
    }
    closedir(dp);
}
 
void s_printf(char *filename,int depth)
{
    while(depth-- > 0)
        printf("|  ");
    printf("|--");
    printf("%s\n",filename);
}
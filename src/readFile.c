#include<project.h>
#include<stdio.h>
void readFile(const char *filePath,char *buffer){
	FILE*fp=fopen(file,"r");
	puts(file);
	if(fp==NULL){
	    printf("file doesn't exist\n");
	}else {
        fread(buff, 256, 256, fp);
        puts(buff);
	}	
}		

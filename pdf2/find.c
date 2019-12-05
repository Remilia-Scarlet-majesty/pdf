#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<string.h>

int find(char str[])
{
	char str1[100];
	FILE*fp;
	if ((fp=fopen("tag.txt","r"))==NULL)
	{
		printf("cannot open this file .\n");
		exit(0);
	}
	strcat(str,"\n");
	while(fgets(str1,100,fp)!=NULL)
	{
		if(!strcmp(str,str1))
		{
			return 1;
		}
	}
	return 0;
}

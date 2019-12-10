#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#ifdef FIND_C
#else 
#define FIND_C
int find1(char str[])
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
int find2(char str[])
{
	char str1[100];
	FILE*fp;
	if ((fp=fopen("cat.txt","r"))==NULL)
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

#endif

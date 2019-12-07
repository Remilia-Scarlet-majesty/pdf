#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#include"cal.c"
#include"def.h"
void addbook()
{
	struct pdf temp;
	FILE*fp;
	if ((fp=fopen("info.csv","a+"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	printf("Enter your book's name,total pages,and pages you have read in order.\n");
	scanf("%s%d%d",temp.name,&temp.pageall,&temp.read);
	getchar();
	fprintf(fp,"%s ,%d,%d,%d,\n",temp.name,temp.pageall,temp.read,temp.lin);
	plus();
	fclose(fp);
}


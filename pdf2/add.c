#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#include"cal.c"
#include"find.c" 
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
	temp.star=0;
	printf("input a category of this book\n");
	scanf("%s",temp.cat);
	if(!find2(temp.cat)){
	FILE*tp;
	if ((tp=fopen("cat.txt","a+"))==NULL)//update "tag.txt"
		{
			printf("cannot open tag.txt. Process failed.\n");
			exit(0);
		}
	fprintf(tp,"%s",temp.cat);
	plus2();
	fclose(tp);
 } 

	fprintf(fp,"%s ,%d,%d,%d,%d,%s \n",temp.name,temp.pageall,temp.read,temp.lin,temp.star,temp.cat);
	plus();
	fclose(fp);
}


#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#include"find.c"
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
	scanf("%s %d%d",temp.name,&temp.pageall,&temp.read);
	getchar();
	fclose(fp);
	
	int x=0,i;
	char c;
	printf("please put in  tags.if you want press y\n");
	while((c=getch())=='y')
	{
		printf("y\n");
		gets(temp.line[x]);
		if(!find(temp.line[x]))
			{
				if ((fp=fopen("tag.txt","a+"))==NULL)
					{
						printf("cannot open this file .\n");
						exit(0);
					}
				fputs(temp.line[x],fp);
				plus1();
				fclose(fp);
			}
		printf("please put in  tags.if you want press y\n");
		x++;
	}
	temp.lin=x;
	if ((fp=fopen("info.csv","a+"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	fprintf(fp,"%s   %d    %d,%d,",temp.name,temp.pageall,temp.read,temp.lin);
	for(i=0;i<x;i++)
	{
		fputs(temp.line[i],fp);
		fprintf(fp,",,");
	}
	fprintf(fp,"\n");
	fclose(fp);
	
	plus();
}


#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#include"cal.c"
#include"def.h"

void delbook()
{
	char s[100];
	FILE*fp;
	if ((fp=fopen("info.csv","r"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	FILE*hp;
	printf("all the books here\n");
	int x=readnum(),i,j,t;
	struct pdf tem[x];
	for(i=0;i<x;i++)
	{
		
		fscanf(fp,"%s   %d    %d,%d,",tem[i].name,&tem[i].pageall,&tem[i].read,&tem[i].lin);
		fscanf(fp,"%s\n",tem[i].line[0]);
				if(!strcmp(tem[i].line[0],s))
				{
					printf("%s\n",tem[i].name);
				}
		for(j=1;j<tem[i].lin;j++)
		fscanf(fp,",,%s\n",tem[i].line[j]);
		fscanf(fp,",,\n");
	}fclose(fp);
	for(i=0;i<x;i++)
	{
		printf("%d.%s\n",i+1,tem[i].name);
	}
	printf("please input no you want to del\n");
	int n;
	scanf("%d",&n);
	if ((hp=fopen("info.csv","w"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	for(i=0;i<x;i++)
	{
		if(i!=(n-1))
		{
			fprintf(fp,"%s   %d    %d,%d,",tem[i].name,tem[i].pageall,tem[i].read,tem[i].lin);
			for(j=0;j<tem[i].lin;j++)
				{
					fputs(tem[i].line[j],fp);
					fprintf(fp,"\n,,");
				}
				fprintf(fp,"\n");
		}
	}
	minus();
	fclose(fp);
	//remove("info.csv");
	//rename("tem.csv","info.csv");
}


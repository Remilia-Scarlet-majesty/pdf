#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#include"cal.c"
#include"def.h"
void sort()
{
	int x,i,t,j,m,n;
	FILE*hp;
	if ((hp=fopen("calt.txt","r"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	fscanf(hp,"%d",&m);
	fclose(hp);
	char arr[m][100];
	if ((hp=fopen("tag.txt","r"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	printf("all the tags:\n");
	for(i=0;i<m;i++)
	{
		fscanf(hp,"%s",arr[i]);
		printf("%d.",i+1);
		puts(arr[i]);
	}
	fclose(hp);
	printf("input the no of tag you want to sort.\n");
	scanf("%d",&n);
	FILE*fp;
	if ((fp=fopen("info.csv","r"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}	
	x=readnum();
    struct pdf tem[x];
	for(i=0;i<x;i++)
	{
		fscanf(fp,"%s   %d    %d,%d,",tem[i].name,&tem[i].pageall,&tem[i].read,&tem[i].lin);
		fscanf(fp,"%s\n",tem[i].line[0]);
		//strcat(tem[i].line[0],"\n");
				if(!strcmp(tem[i].line[0],arr[n-1]))
				{
					printf("%s\n",tem[i].name);
				}
		for(j=1;j<tem[i].lin;j++)
			{
				fscanf(fp,",,%s\n",tem[i].line[j]);
				//strcat(tem[i].line[j],"\n");
				if(!strcmp(tem[i].line[j],arr[n-1]))
				{
					printf("%s\n",tem[i].name);
				}
			}
	fscanf(fp,",,\n");
}
	fclose(fp);

}


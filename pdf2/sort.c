#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include"find.c"
#include"cal.c"
#include"def.h"
void sort1()
{
	int i,t,j,m,n;
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
	//print tags
	
	int d;
	struct pdf *tem;
	FILE*fp;
	d=readnum();
	if ((fp=fopen("info.csv","r"))==NULL)
		{
			printf("cannot open info.csv .\n");
			exit(0);
		}
		//else printf("Open.Done.\n");
	tem=malloc(d*sizeof(struct pdf));
	for(i=0;i<d;i++)
		{
			fscanf(fp,"%s ,%d,%d,%d,%d,%s",tem[i].name,&tem[i].pageall,&tem[i].read,&tem[i].star,&tem[i].lin,tem[i].cat);
					fseek(fp,1L,SEEK_CUR);
					fseek(fp,1L,SEEK_CUR);
			for(j=0;j<tem[i].lin;j++)
				{
					//avoid to input the ","
					fscanf(fp,"%s",tem[i].line[j]);
					
						if(!strcmp(tem[i].line[j],arr[n-1]))
						printf("%s\n",tem[i].name);
					
					fseek(fp,1L,SEEK_CUR);
					fseek(fp,1L,SEEK_CUR);
				}
				if(tem[i].lin!=0){
					fseek(fp,1L,SEEK_CUR);
					fseek(fp,1L,SEEK_CUR);
				}
		}
	fclose(fp);
}

void sort2()
{
	int i,t,j,m,n;
	FILE*hp;
	if ((hp=fopen("calc.txt","r"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	fscanf(hp,"%d",&m);
	fclose(hp);
	char arr[m][100];
	if ((hp=fopen("cat.txt","r"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	printf("all the categories:\n");
	for(i=0;i<m;i++)
	{
		fscanf(hp,"%s",arr[i]);
		printf("%d.",i+1);
		puts(arr[i]);
	}
	fclose(hp);
	printf("input the no of tag you want to sort.\n");
	scanf("%d",&n);
	//print tags
	
	int d;
	struct pdf *tem;
	FILE*fp;
	d=readnum();
	if ((fp=fopen("info.csv","r"))==NULL)
		{
			printf("cannot open info.csv .\n");
			exit(0);
		}
		//else printf("Open.Done.\n");
	tem=malloc(d*sizeof(struct pdf));
	for(i=0;i<d;i++)
		{
			fscanf(fp,"%s ,%d,%d,%d,%d,%s",tem[i].name,&tem[i].pageall,&tem[i].read,&tem[i].star,&tem[i].lin,tem[i].cat);
					fseek(fp,1L,SEEK_CUR);
					fseek(fp,1L,SEEK_CUR);
			for(j=0;j<tem[i].lin;j++)
				{
					//avoid to input the ","
					fscanf(fp,"%s",tem[i].line[j]);
					
						
					
					fseek(fp,1L,SEEK_CUR);
					fseek(fp,1L,SEEK_CUR);
				}
				if(tem[i].lin!=0){
					fseek(fp,1L,SEEK_CUR);
					fseek(fp,1L,SEEK_CUR);
				}
				if(!strcmp(tem[i].cat,arr[n-1]))
						printf("%s\n",tem[i].name);
		}
	fclose(fp);
}


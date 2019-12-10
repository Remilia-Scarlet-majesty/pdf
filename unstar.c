#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include"cal.c"
#include"def.h"
void unstar()
{
	int i,j,d,m;
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
			if(tem[i].lin==0)
				{
					fseek(fp,1L,SEEK_CUR);
					fseek(fp,1L,SEEK_CUR);
				}
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
		}
		
	
	fclose(fp);
//	printf("Input data.Done.\n"); debug expression
	printf("Book List:\n");
	for(i=0;i<d;i++)
	{
		if(tem[i].star)
		printf("%dth %s   Page:%d   Finish:%d   TagNumbers:%d\n",i+1,tem[i].name,tem[i].pageall,tem[i].read,tem[i].lin);
	}
	printf("Which book you want to star?\n");
	scanf("%d",&m);
	tem[m-1].star=0;
	
	if ((fp=fopen("info.csv","w"))==NULL)
		{
			printf("cannot open info.csv .\n");
			exit(0);
		}
	
	for(i=0;i<d;i++)
	{
		fprintf(fp,"%s ,%d,%d,%d,%d,%s ,",tem[i].name,tem[i].pageall,tem[i].read,tem[i].star,tem[i].lin,tem[i].cat);
		for(j=0;j<tem[i].lin;j++)
			{
				fprintf(fp,"%s ,",tem[i].line[j]);
			}
			//adjust to the initial format//adjust to the initial format
		fprintf(fp,"\n");
		}
}

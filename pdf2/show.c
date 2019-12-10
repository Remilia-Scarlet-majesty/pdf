#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include"cal.c"
#include"def.h"
void show()
{
	int i,j,d;
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
		}
	
	fclose(fp);
//	printf("Input data.Done.\n"); debug expression
for(i=0;i<d;i++)
{
	if(tem[i].star)
	puts(tem[i].name);
}
}

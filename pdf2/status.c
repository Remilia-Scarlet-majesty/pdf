#include<stdio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include"def.h"
#include"cal.c"
void status()
{	int i,d,j;
	struct pdf *tem;
	d=readnum();
	tem=malloc(d*sizeof(struct pdf));
	FILE*fp;

	if ((fp=fopen("info.csv","r"))==NULL)
	{
		printf("Cannot open info file.\n");
		exit(0);
	}
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
	printf("Finish book list:\n");
	for(i=0;i<d;i++)
	{
		if (tem[i].read==tem[i].pageall)
		puts(tem[i].name);
	}
	printf("Unfinish book list:\n");
	for(i=0;i<d;i++)
	{
		if(tem[i].read<tem[i].pageall&&tem[i].read!=0)
		puts(tem[i].name);
	}
	printf("Unread book list:\n");
	for(i=0;i<d;i++)
	{
		if(tem[i].read==0)
		puts(tem[i].name);
	}
	free(tem);
	fclose(fp);
 } 


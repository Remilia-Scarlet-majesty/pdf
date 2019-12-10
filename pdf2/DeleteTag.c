#include<stdio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include"cal.c"
#include"def.h"
int deltag()
{	int DeBook,DeTag;
	char DeBooks[100],DeTags[100],NDeTags[100];
	FILE*fp;
	int i,j,d;
	struct pdf *tem;
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
	printf("Book List:\n");
	for(i=0;i<d;i++)
	printf("%dth %s   Page:%d   Finish:%d   TagNumbers:%d\n",i+1,tem[i].name,tem[i].pageall,tem[i].read,tem[i].lin);
	printf("Which book's tag do you want to delete?Input the num of book\n");
	scanf("%d",&DeBook);
	DeBook--;
	printf("Book Name:%s\n",tem[DeBook].name);
	for(i=0;i<tem[DeBook].lin;i++)
	printf("Tag%d:%s\n",i+1,tem[DeBook].line[i]);
	printf("Which one do you want to delete? Input the Tag num\n");
	scanf("%d",&DeTag);
	DeTag--;
	strcpy(DeTags,tem[DeBook].line[DeTag]);
	FILE*hp;
	if ((hp=fopen("temp.csv","w"))==NULL)
		{
			printf("cannot open new info file. Process failed.\n");
			exit(0);
		}
	for(i=0;i<d;i++)
	{	if(i!=DeBook)
		{
			
			fprintf(hp,"%s ,%d,%d,%d,%d,%s ,",tem[i].name,tem[i].pageall,tem[i].read,tem[i].star,tem[i].lin,tem[i].cat);
			for(j=0;j<tem[i].lin;j++)
			{
				fprintf(hp,"%s ,",tem[i].line[j]);
			}
			//adjust to the initial format//adjust to the initial format
		fprintf(hp,"\n");
		}
		else
		{	tem[i].lin--;
			fprintf(hp,"%s ,%d,%d,%d,%d,%s ,",tem[i].name,tem[i].pageall,tem[i].read,tem[i].star,tem[i].lin,tem[i].cat);
			for(j=0;j<tem[i].lin+1;j++)
			if (j!=DeTag)
			{
				fprintf(hp,"%s ,",tem[i].line[j]);
			}
			fprintf(hp,"\n");
			//adjust to the initial format//adjust to the initial format
			}	
		
	}
	fclose(hp);
	remove("info.csv");
	rename("temp.csv","info.csv");
	free(tem);
	printf("Done.\n");
	/*FILE*tp;
	if ((tp=fopen("tag.txt","r"))==NULL)//update "tag.txt"
		{
			printf("cannot open tag.txt. Process failed.\n");
			exit(0);
		}
	FILE*ntp;
		if ((ntp=fopen("ntag.txt","w"))==NULL)
		{
			printf("cannot establish ntag.txt. Process failed.\n");
			exit(0);
		}
	while((fgets(NDeTags,100,tp))!=NULL)
	{	if(strcmp(NDeTags,DeTags)!=0)
		fprintf(ntp,"%s",NDeTags);
	}
	fclose(tp);
	fclose(ntp);
	remove("tag.txt");
	rename("ntag.txt","tag.txt"); */
 } 


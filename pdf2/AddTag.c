#include<stdio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include"cal.c"
#include"def.h"
int addtag()
{	int d,i,j,AddBook,AddTag;
	char AddBooks[100],AddTags[100],NAddTags[100],rubbish[20],dou[5];
	strcpy(dou,",,");
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
		fscanf(fp,"%s   %d    %d,%d,",tem[i].name,&tem[i].pageall,&tem[i].read,&tem[i].lin);
	
		for(j=0;j<tem[i].lin;j++)
		{	if(j==0)
			{
				fgets(rubbish,1,fp);//avoid to input the ","
				fgets(tem[i].line[j],100,fp);
			}
			else
			{
				fgets(rubbish,3,fp);//avoid to input the ","
				fgets(tem[i].line[j],100,fp);
			}
	}
		fgets(rubbish,18,fp);
	}
	fclose(fp);
//	printf("Input data.Done.\n"); debug expression
	printf("Book List:\n");
	for(i=0;i<d;i++)
	printf("%dth %s   Page:%d   Finish:%d   TagNumbers:%d\n",i+1,tem[i].name,tem[i].pageall,tem[i].read,tem[i].lin);
	printf("Which book's tag do you want to add tag?Input the num of book\n");
	scanf("%d",&AddBook);
	AddBook--;
	printf("Book Name:%s\n",tem[AddBook].name);
	for(i=0;i<tem[AddBook].lin;i++)
	printf("Tag%d:%s\n",i+1,tem[AddBook].line[i]);
	printf("Please input the new tag\n");
	scanf("%s",AddTags);
	FILE*hp;
	if ((hp=fopen("temp.csv","w"))==NULL)
		{
			printf("cannot open new info file. Process failed.\n");
			exit(0);
		}
	for(i=0;i<d;i++)
	{	if(i!=AddBook)
		{
			
			fprintf(hp,"%s   %d    %d,%d,",tem[i].name,tem[i].pageall,tem[i].read,tem[i].lin);
			for(j=0;j<tem[i].lin;j++)
			{
				if(j==0)
				fprintf(fp,"%s",tem[i].line[j]);
				else
				fprintf(fp,",,%s",tem[i].line[j]);
			}
			fprintf(hp,"%s\n",dou);
			//adjust to the initial format//adjust to the initial format
		}
		else
		{	tem[i].lin++;
			fprintf(hp,"%s   %d    %d,%d,",tem[i].name,tem[i].pageall,tem[i].read,tem[i].lin);
			for(j=0;j<tem[i].lin-1;j++)
			{
				if(j==0)
				fprintf(fp,"%s",tem[i].line[j]);
				else
				fprintf(fp,",,%s",tem[i].line[j]);
			}
			fprintf(fp,",,%s\n",AddTags);
			fprintf(hp,"%s\n",dou);
			//adjust to the initial format//adjust to the initial format
			}	
		
	}
	fclose(hp);
	remove("info.csv");
	rename("temp.csv","info.csv");
	printf("Done.\n");
	printf("The new tag list now is:\n");
	/*print the new tag list.This function can be deleted if necessary.*/	
	for(i=0;i<tem[AddBook].lin-1;i++)
	printf("Tag%d:%s\n",i+1,tem[AddBook].line[i]);
	printf("Tag%d:%s\n",tem[AddBook].lin,AddTags);
	free(tem);

	FILE*tp;
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
	while((fgets(NAddTags,100,tp))!=NULL)
	{	
		fprintf(ntp,"%s",NAddTags);
	}
	fprintf(ntp,"%s",AddTags);
	fclose(tp);
	fclose(ntp);
	remove("tag.txt");
	rename("ntag.txt","tag.txt"); 
 } 


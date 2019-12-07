#include<stdio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include"cal.c"
#include"def.h"
#include"find.c"
void getname(char s[]);
int addtag()
{	int d,i,j,AddBook,AddTag;
	char AddBooks[100],AddTags[100],NAddTags[100],rubbish[100],dou[5];
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
			fscanf(fp,"%s ,%d,%d,%d,",tem[i].name,&tem[i].pageall,&tem[i].read,&tem[i].lin);
			if(tem[i].lin==0)
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
	printf("Which book's tag do you want to add tag?Input the num of book\n");
	scanf("%d",&AddBook);
	getchar();
	AddBook--;
	printf("Book Name:%s\n",tem[AddBook].name);
	for(i=0;i<tem[AddBook].lin;i++)
	printf("Tag%d:%s\n",i+1,tem[AddBook].line[i]);
	printf("Please input the new tag\n");
	getname(AddTags);
	FILE*hp;
	if ((hp=fopen("temp.csv","w"))==NULL)
		{
			printf("cannot open new info file. Process failed.\n");
			exit(0);
		}
	for(i=0;i<d;i++)
	{	if(i!=AddBook)
		{
			
			fprintf(hp,"%s ,%d,%d,%d,",tem[i].name,tem[i].pageall,tem[i].read,tem[i].lin);
			for(j=0;j<tem[i].lin;j++)
			{
				fprintf(hp,"%s ,",tem[i].line[j]);
			}
			//adjust to the initial format//adjust to the initial format
		fprintf(hp,"\n");
		}
		else
		{	tem[i].lin++;
			fprintf(hp,"%s ,%d,%d,%d,",tem[i].name,tem[i].pageall,tem[i].read,tem[i].lin);
			for(j=0;j<tem[i].lin-1;j++)
			{
			
				fprintf(hp,"%s ,",tem[i].line[j]);
			}
			fprintf(hp,"%s ,\n",AddTags);
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


	if(!find(AddTags)){
	FILE*tp;
	if ((tp=fopen("tag.txt","a+"))==NULL)//update "tag.txt"
		{
			printf("cannot open tag.txt. Process failed.\n");
			exit(0);
		}
	fprintf(tp,"%s",AddTags);
	plus1();
	fclose(tp);
 } 
}
void getname(char s[])
{
	int i;char c;
	for(i=0;i<99&&(c=getchar())!='\n';i++)
		{
			s[i]=c;
		}
	s[i]='\0';
}


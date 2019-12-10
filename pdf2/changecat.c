#include<stdio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include"cal.c"
#include"def.h"
#include"find.c"
void getname(char s[]);
int changecat()
{	int d,i,j,AddBook,AddTag;
	char AddBooks[100],AddTags[100],NAddTags[100];
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
	printf("Book List:\n");
	for(i=0;i<d;i++)
	printf("%dth %s   Page:%d   Finish:%d   TagNumbers:%d\n",i+1,tem[i].name,tem[i].pageall,tem[i].read,tem[i].lin);
	printf("Which book's tag do you want to add tag?Input the num of book\n");
	scanf("%d",&AddBook);
	getchar();
	printf("Please input the new category\n");
	scanf("%s",tem[AddBook-1].cat);
	strcpy(tem[AddBook-1].cat,AddTags);
	FILE*hp;
	if ((hp=fopen("temp.csv","w"))==NULL)
		{
			printf("cannot open new info file. Process failed.\n");
			exit(0);
		}
	for(i=0;i<d;i++)
	{	
			fprintf(hp,"%s ,%d,%d,%d,%d,%s ,",tem[i].name,tem[i].pageall,tem[i].read,tem[i].star,tem[i].lin,tem[i].cat);
			for(j=0;j<tem[i].lin;j++)
			{
				fprintf(hp,"%s ,",tem[i].line[j]);
			}
			//adjust to the initial format//adjust to the initial format
		fprintf(hp,"\n");
		
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


	if(!find2(AddTags)){
	FILE*tp;
	if ((tp=fopen("cat.txt","a+"))==NULL)//update "tag.txt"
		{
			printf("cannot open tag.txt. Process failed.\n");
			exit(0);
		}
	fprintf(tp,"%s",AddTags);
	plus2();
	fclose(tp);
 } 
}

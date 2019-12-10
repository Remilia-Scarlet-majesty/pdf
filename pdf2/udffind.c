#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
#define N 3
#include"cal.c"
#include"def.h"
void udffind()
{	
	struct pdf *tem;
	int i,j,ii,jj,d,len,decide[100]={0};
	char exam1[5],exam2[5],exam[15];
	FILE *fp;
	d=readnum();
	tem=malloc(d*sizeof(struct pdf));
	if((fp=fopen("info.csv","r"))==NULL)
	{
		printf("Can not open info file.\n");
		exit(0);
	};
	printf("please input the keyword\n");
	scanf("%s",exam);
	printf("Book list:\n");
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
	
	for(i=0;i<d;i++)//exam all the book name
	{	len=strlen(tem[i].name);
		for(j=0;j<len-N+1;j++)
			for(ii=0;ii<strlen(exam)-N+1;ii++)
			{
				for(jj=0;jj<N;jj++)
				{
					exam1[jj]=tem[i].name[j+jj];
					exam2[jj]=exam[ii+jj];
				}
				exam1[N]='\0';exam2[N] ='\0';
				if (strcmp(exam1,exam2)==0)
				{	decide[i]=1;//mark the correct book  
				
				}
			}
	}
	for(i=0;i<d;i++)
		{	
			if(strcmp(tem[i].name,exam)==0)
			decide[i]=1;
		}
	for(i=0;i<d;i++)
	if(decide[i])
	{
		printf("%dth: ",i+1);puts(tem[i].name);
	}
	free(tem);
	fclose(fp);
}


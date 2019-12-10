#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#ifdef CAL_H
#else
#define CAL_H
void plus()
{
	int d;
	FILE*fp;
	if ((fp=fopen("cal.txt","r"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	fscanf(fp,"%d",&d);
	d++;
	fclose(fp);
	if ((fp=fopen("cal.txt","w"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	fprintf(fp,"%d",d);
	fclose(fp);
}

void minus()
{
	int d;
	FILE*fp;
	if ((fp=fopen("cal.txt","r"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	fscanf(fp,"%d",&d);
	d--;
	fclose(fp);
	if ((fp=fopen("cal.txt","w"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	fprintf(fp,"%d",d);
	fclose(fp);
}

int readnum()
{
	int d;
	FILE*fp;
	if ((fp=fopen("cal.txt","r"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	fscanf(fp,"%d",&d);
	fclose(fp);
	return d;
}

void minus1()
{
	int d;
	FILE*fp;
	if ((fp=fopen("calt.txt","r"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	fscanf(fp,"%d",&d);
	d--;
	fclose(fp);
	if ((fp=fopen("calt.txt","w"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	fprintf(fp,"%d",d);
	fclose(fp);
}
void plus1()
{
	int d;
	FILE*fp;
	if ((fp=fopen("calt.txt","r"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	fscanf(fp,"%d",&d);
	d++;
	fclose(fp);
	if ((fp=fopen("calt.txt","w"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	fprintf(fp,"%d",d);
	
	fclose(fp);
}
void plus2()
{
	int d;
	FILE*fp;
	if ((fp=fopen("calc.txt","r"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	fscanf(fp,"%d",&d);
	d++;
	fclose(fp);
	if ((fp=fopen("calc.txt","w"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	fprintf(fp,"%d",d);
	
	fclose(fp);
}
void minus2()
{
	int d;
	FILE*fp;
	if ((fp=fopen("calc.txt","r"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	fscanf(fp,"%d",&d);
	d--;
	fclose(fp);
	if ((fp=fopen("calc.txt","w"))==NULL)
		{
			printf("cannot open this file .\n");
			exit(0);
		}
	fprintf(fp,"%d",d);
	fclose(fp);
}
#endif


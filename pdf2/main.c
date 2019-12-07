#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#include"add.c"
#include"DeleteTag.c"
#include"del.c"
#include"sort.c"
#include"def.h"
#include"AddTag.c"
#include"printbook.c"
int main()
{
	int n;
	char c='y';
	while(c=='y'){
	printf("1-添加一本书的信息");
	printf("          ");
	printf("2-根据标签分类\n");
	printf("3-删除一本书有关信息"); 
	printf("        ");
	printf("4-删除一本书的某标签\n");
	printf("5-为某本书添加标签");
	printf("          ");
	printf("6-打印信息\n");
	printf("0-exit\n");
	printf("please input the number.\n");
	scanf("%d",&n);
	if(n>=0&&n<=6)
	{
		switch(n){
			case 1:addbook();break;
			case 2:sort();break;
			case 3:delbook();break;
			case 4:deltag();break;
			case 5:addtag();break;
			case 6:printbook();break;
			case 0:return 0;
		}
	}
	printf("If you want to continue,press y.else  随便按\n");
	c=getch();
	putchar(c);
	putchar('\n');
}
}


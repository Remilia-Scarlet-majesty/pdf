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
#include"show.c"
#include"star.c"
#include"unstar.c"
#include"udffind.c"
#include"status.c"
#include"changecat.c"
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
	printf("7-标记星号          "); 
	printf("        ");
	printf("8-解除标记\n");
	printf("9-查看标记书籍");
	printf("              ");
	printf("10-显示状态\n");
	printf("11-模糊书名查找");
	printf("             ");
	printf("12-更改阅读状态\n");
	printf("13-根据书籍管理类别查找");
	printf("     ");
	printf("14-更改书籍管理类别\n");
	printf("0-exit\n");
	printf("please input the number.\n");
	scanf("%d",&n);
	if(n>=0&&n<=14)
	{
		switch(n){
			case 1:addbook();break;
			case 2:sort1();break;
			case 3:delbook();break;
			case 4:deltag();break;
			case 5:addtag();break;
			case 6:printbook();break;
			case 7:star();break;
			case 8:unstar();break;
			case 9:show();break;
			case 10:status();break;
			case 11:udffind();break;
			case 12://等着zmr 
			case 13:sort2();break;
			case 14:changecat();break;
			case 0:return 0;
		}
	}
	printf("If you want to continue,press y.else  随便按\n");
	c=getch();
	putchar(c);
	putchar('\n');
}
}


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
	printf("1-���һ�������Ϣ");
	printf("          ");
	printf("2-���ݱ�ǩ����\n");
	printf("3-ɾ��һ�����й���Ϣ"); 
	printf("        ");
	printf("4-ɾ��һ�����ĳ��ǩ\n");
	printf("5-Ϊĳ������ӱ�ǩ");
	printf("          ");
	printf("6-��ӡ��Ϣ\n");
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
	printf("If you want to continue,press y.else  ��㰴\n");
	c=getch();
	putchar(c);
	putchar('\n');
}
}


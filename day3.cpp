#include<stdio.h>
#include<string.h>
//#define MAX(X,Y) (X>Y?X:Y)
//int Add(int n, int m)
//{
//	int a = 10;
//	printf("%d\n", a);
//	a++;
//	return n + m;
//}
struct Book
{
	char name[20];
	short price;
};
int main()
{
	int ch;
	while ((ch = getchar()) != EOF)
		putchar(ch);
	/*int ch = getchar();
	putchar(ch);*/
	/*int i = 0;
	while (i < 10)
	{
		i++;
		if (i == 3)
			continue;
		printf("%d ", i);
	}*/
	/*int day = 1;
	switch (day)
	{
	case 1:
		printf("day1");
		break;
	case 2:
	case 3:
	default:
		printf("err");
		break;
	}*/
	/*int a = 1;
	int b = 2;
	if (a == 0)
		if (b == 2)
			printf("b");
		else
			printf("!b");
	else
		printf("a");*/
	/*struct Book b1 = { "c语言",56 };
	printf("%s\n", b1.name);
	printf("%d\n", b1.price);
	struct Book* pb = &b1;
	printf("%s\n", (*pb).name);
	printf("%s\n", pb->name);
	strcpy_s(b1.name, "C++");
	printf("%s\n", pb->name);*/
	/*int a, b, i, j;
	a = 1;
	b = 2;
	i = 3;
	j = 4;
	a = Add(a, b);
	i = Add(i, j);
	int num = MAX(i, j);
	printf("%d\n", num);*/
	/*int a = 10;
	int* p = &a;
	*p = 20;
	printf("%d\n", a);
	printf("%p\n", p);*/
	/*printf("%d\n", sizeof(char*));
	printf("%d\n", sizeof(short*));
	printf("%d\n", sizeof(int *));
	printf("%d\n", sizeof(double*));*/
	return 0;
}
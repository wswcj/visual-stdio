#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	int a = 3;
	int b = 5;
	int c = (a > b ? a : b);
	printf("%d\n", c);
	return 0;
}
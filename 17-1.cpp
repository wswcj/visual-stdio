#include<iostream>
#include<stdio.h>
using namespace std;
void test1()
{
	printf_s("%d", printf_s("%d", printf_s("%d", 43)));
}
int main()
{
	test1();
	return 0;
}
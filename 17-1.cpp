#include<iostream>
#include<stdio.h>
using namespace std;
void test1()
{
	printf_s("%d", printf_s("%d", printf_s("%d", 43)));
}
int fact(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return n * fact(n - 1);
}
void test2()
{
	int n = 0;
	int ret = 0;
	cin >> n;
	ret = fact(n);
	cout << ret << endl;
}
int fit(int n)
{
	if (n <= 2)
		return 1;
	else
		return fit(n - 1) + fit(n - 2);
}
void test3()
{
	int n = 0;
	cin >> n;
	int ret = 0;
	ret = fit(n);
	cout << ret << endl;
}
int Fit(int n)
{
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	int a = 1;
	int b = 1;
	int c = 0;
	for (int i = 3; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}
void test4()
{
	int n = 0;
	cin >> n;
	int ret = 0;
	ret = Fit(n);
	cout << ret << endl;
}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}
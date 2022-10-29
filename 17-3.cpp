#include<iostream>
using namespace std;
int function1(int x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n % 2 == 1)
	{
		return function1(x, n / 2) * function1(x, n / 2) * x;
	}
	return function1(x, n / 2) * function1(x, n / 2);
}
int function2(int x, int n)
{
	if (n == 0)
		return 1;
	int t = function2(x, n / 2);
	if (n % 2 == 1)
		return t * t * x;
	return t * t;
}
void test1()
{
	int x = 2;
	int n = 3;
	int ret1 = function1(x, n);
	cout << ret1 << endl;
	int ret2 = function2(x, n);
	cout << ret2 << endl;
}
void test2()
{
	int arr[3][4] = { 0 };
	cout << &arr[0] << endl;
	cout << &arr[1][0] << endl;
	cout << &arr[2][0] << endl;
	
}
int main()
{
	test2();
	return 0;
}
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
void MySort(int* arr, int len)
{
	int temp = 0;
	for (int i = 0; i < len-1; i++)
	{
		int flag = 1;
		for (int j = 0; j < len -1 - i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}
void test5()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	MySort(arr,sz);
	for (int i = 0; i < sz; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void test6()
{
	int a = 3;
	int b = 5;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	cout << "a=" << a << "\tb=" << b << endl;
}
void test7()
{
	int arr[9] = { 1,2,3,4,5,4,3,2,1 };
	int ret = 0;
	for (int i = 0; i < 9; i++)
		ret = ret ^ arr[i];
	cout << ret << endl;
}void test8()
{
	int count = 0;
	int num = 127;
	while (num)
	{
		if (num % 2 == 1)
		{
			count++;
		}
		num /= 2;
	}
	cout << count << endl;
}
void test9()
{
	int num = 127;
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) == 1)
		{
			count++;
		}
	}
	cout << count << endl;
}
int main()
{
	//test1();
	//test2();
	//test3();
	test9();
	return 0;
}
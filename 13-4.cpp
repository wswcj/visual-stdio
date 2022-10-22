#include<iostream>
#include<windows.h>
using namespace std;
void test1()
{
	int ret = 0;
	char ch = 0;
	char password[20] = { 0 };
	cout << "请输入密码:" << endl;
	cin >> password;
	while ((ch = getchar()) != '\n')
	{
		;
	}
	cout << "请确认:" << endl;
	ret = getchar();
	if (ret == 'Y')
		cout << "确认成功" << endl;
	else
		cout << "确认失败" << endl;
}
void test2()
{
	int ret = 0;
	while ((ret = getchar()) != EOF)
	{
		if (ret < '0' || ret>'9')
			continue;
		putchar(ret);
	}
}
void test3()
{
	string str1 = "welcome to my home";
	string str2 = "******************";
	int left = 0;
	int right = str1.size() - 1;
	while (left < right)
	{
		cout << str2 << endl;
		str2[left] = str1[left];
		str2[right] = str1[right];
		Sleep(1000);
		system("cls");
		left++;
		right--;
	}
	cout << str2 << endl;

}
void test4()
{
	char password[20] = { 0 };
	int i = 0;
	for ( i = 0; i < 3; i++)
	{
		cout << "请输入密码: ";
		cin >> password;
		if (strcmp(password, "123456") == 0)
		{
			cout << "密码正确" << endl;
			break;
		}
		else
		{
			cout << "密码错误,请重新输入" << endl;
		}
	}
	if (i == 3)
	{
		cout << "密码错误三次，请稍后再试" << endl;
	}
}
void test5()
{
	int n = 18;
	int m = 24;
	int ret = 0;
	while(ret=n%m)
	{
		n = m;
		m = ret;
	}
	cout << m << endl;
}
void test6()
{
	int i = 0;
	int j = 0;
	int sum = 0;
	for (i = 1; i < 100; i++)
	{
		for (j = 2; j < sqrt(i); j++)
		{
			if (i % j == 0)
				break;
		}
		if (j > sqrt(i))
		{
			cout << i << " ";
			sum++;
		}
	}
	cout << endl;
	cout << sum << endl;
}
void test()
{
	for (int i = 2; i < sqrt(9); i++)
	{
		if (9 % i == 0)
			break;

	}
}
void test7()
{
	double a = 0.0;
	int flag = 1;
	for (int i = 1; i < 100; i++)
	{
		a += 1.0 / i * flag;
		flag = -flag;
	}
	cout << a << endl;
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test();
	test7();
	return 0;
}
#pragma once
#include<iostream>
using namespace std;
int& func1()
{
	static int a = 20;
	return a;
}
void test1()
{
	int& ref = func1();
	cout << ref << endl;
	func1() = 200;
	cout << ref << endl;
	const int& ret = 10;
}
int main()
{
	test1();
	return 0;
}
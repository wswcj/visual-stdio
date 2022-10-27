#include<iostream>
using namespace std;
extern const int ext;
void test()
{
	cout << ext << endl;
}
void test1()
{
	//err
	//const int  i, j = 0;
	const int p = 10;
	const void* vp = &p;
	//err
	//void* vp = &p;
	int val = 3;
	const int* ptr = &val;
	val = 5;
	int* t = &val;
	*t = 4;
	cout << val << endl;
	int val1 = 4;
	ptr = &val1;
}
void test2()
{
	const int val1 = 4;
	//err
	//int* const ptr = &val1;
	const int* ptr = &val1;
	cout << *ptr << endl;
}
//class Apple
//{
//public:
//	Apple(int i);
//	const int num;
//};
//Apple::Apple(int i):num(i)
//{
//	
//}
class Apple
{
public:
	const int num=10;
	//static const int num=10;
};
//const int Apple::num = 10;
class Person
{
public:
	static int num;
};
int Person::num = 10;
void test3()
{
	Apple a1;
	cout << a1.num << endl;
	Person p1;
	cout << p1.num << endl;
}
int main()
{
	test3();
	return 0;
}
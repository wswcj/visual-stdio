#include<iostream>
using namespace std;
class Person
{
public:
	int age;
	static int a;
	void fun();
	static void fun1();
};
int Person::a = 0;
int main()
{
	Person p;
	cout << sizeof(p) << endl;
	return 0;
}
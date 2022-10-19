#include<iostream>
using namespace std;

template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->name = name;
		this->age = age;
	}
	void showPerson()
	{
		cout << this->name << this->age << "岁" << endl;
	}
	T1 name;
	T2 age;
};
void printPerson(Person<string,int>&p)
{
	p.showPerson();
}
void test()
{
	Person<string, int> p("小悟空", 20000);
	printPerson(p);
}
int main()
{
	test();
	return 0;
}
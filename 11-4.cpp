#include<iostream>
using namespace std;
template<class t1,class t2>
class Person
{
	friend void printPerson(Person<t1, t2>& p)
	{
		cout <<p.name << p.age <<"岁"<< endl;
	}
public:
	Person(t1 name, t2 age)
	{
		this->name = name;
		this->age = age;
	}
private:
	t1 name;
	t2 age;
};
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
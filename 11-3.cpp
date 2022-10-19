#include<iostream>
using namespace std;
template<class t1,class t2>
class Person
{
public:
	Person(t1 name, t2 age);
	void showPerson();
	t1 name;
	t2 age;
};
template<class t1,class t2>
Person<t1, t2>::Person(t1 name,t2 age)
{
	this->name = name;
	this->age = age;
}
template<class t1,class t2>
void Person<t1, t2>::showPerson()
{
	cout << this->name << this->age << "岁" << endl;
}
void test()
{
	Person<string, int> p("小悟空", 20000);
	p.showPerson();
}
int main()
{
	test();
	return 0;
}
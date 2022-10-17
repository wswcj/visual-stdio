#include<iostream>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

template<class T>
bool my_compare(T& a, T& b)
{
	if (a == b)
		return true;
	else
		return false;
}

template<> bool my_compare(Person& p1, Person& p2)
{
	if (p1.name == p2.name && p1.age == p2.age)
		return true;
	else
		return false;
}

void test()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	bool ret = my_compare(p1, p2);
	if (ret)
		cout << "p1=p2" << endl;
	else
		cout << "p1!=p2" << endl;
}
int main()
{
	test();
	return 0;
}
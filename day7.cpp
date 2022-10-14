#include<iostream>
using namespace std;
class Person
{
public:
	Person(int age)
	{
		this->age = age;
	}
	Person& PersonAddPerson(Person p)
	{
		this->age += p.age;
		return *this;
	}
	int age;
};
void test()
{
	Person p(10);
	p.PersonAddPerson(p).PersonAddPerson(p).PersonAddPerson(p);
	cout << p.age << endl;
}
int main()
{
	test();
	return 0;
}
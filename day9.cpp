#include<iostream>
using namespace std;
class Person
{
public:
	void ShowPerson() const
	{
		this->b = 100;
	}
	int a=10;
	mutable int b;
};
void test()
{
	Person p;
	p.ShowPerson();
}
int main()
{
	test();
	return 0;
}
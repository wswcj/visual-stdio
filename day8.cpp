#include<iostream>
using namespace std;
class Person
{
public:
	void ShowClassName()
	{
		cout << "this is person class" << endl;
	}
	void ShowAge()
	{
		if (this == NULL)
		{
			return;
		}
		cout << this->age << endl;
	}
	int age;
};
int main()
{
	Person* p = NULL;
	p->ShowClassName();
	p->ShowAge();
	return 0;
}
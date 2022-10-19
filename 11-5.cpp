#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Person
{
public:
	Person(string name,int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};
void test2()
{
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << endl;
		}
		cout << endl;
	}
}
void test1()
{
	vector<Person> v;
	Person p1("aaa", 10);
	Person p2("aaa", 10);
	Person p3("aaa", 10);
	Person p4("aaa", 10);
	Person p5("aaa", 10);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	for (vector<Person>::iterator it=v.begin(); it != v.end(); it++)
		cout << (*it).name << (*it).age << "岁" << endl;
}
void test()
{
	vector<int> v;
	for (int i = 10; i < 100; i += 10)
	{
		v.push_back(i);
	}
	vector<int>::iterator pbegin = v.begin();
	vector<int>::iterator pend = v.end();
	while (pbegin != pend)
	{
		cout << *pbegin << endl;
		pbegin++;
	}
	cout << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
}
int main()
{
	test2();
	return 0;
}
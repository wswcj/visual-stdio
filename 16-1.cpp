#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//count
void test1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(4);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	int num = count(v1.begin(), v1.end(), 4);
	cout << "4的个数:" << num << endl;
}
class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	bool operator==(const Person& p)
	{
		if (this->age == p.age)
			return true;
		else
			return false;
	}
	string name;
	int age;
};
//Person类 count
void test2()
{
	vector<Person> v1;
	Person p1("tom", 35);
	Person p2("tom", 35);
	Person p3("tom", 33);
	Person p4("tom", 34);
	Person p5("tom", 32);
	Person p6("tom", 34);
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);
	v1.push_back(p6);
	Person pp("jack", 34);
	int num = count(v1.begin(), v1.end(), pp);
	cout << "和pp年龄一样的有" << num << "个" << endl;
}
class Greater20
{
public:
	bool operator()(int v)
	{
		return v > 20;
	}
};
//count_if
void test3()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(20);
	v1.push_back(30);
	int num = count_if(v1.begin(), v1.end(), Greater20());
	cout << num << endl;
}
class Greater33
{
public:
	bool operator()(const Person& p)
	{
		return p.age > 33;
	}
};
//Person类 count_if
void test4()
{
	vector<Person> v1;
	Person p1("tom", 35);
	Person p2("tom", 35);
	Person p3("tom", 33);
	Person p4("tom", 33);
	Person p5("tom", 32);
	Person p6("tom", 34);
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);
	v1.push_back(p6);
	int num = count_if(v1.begin(), v1.end(), Greater33());
	cout << num << endl;
}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}
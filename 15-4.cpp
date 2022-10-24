#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class MyPrint
{
public:
	void operator()(int v1)
	{
		cout << v1 << " ";
	}

};
//for_each
void test1()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
}
class TransForm
{
public:
	int operator()(int val)
	{
		return val * 10;
	}
};
//transform
void test2()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int> v2;
	v2.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), TransForm());
	for_each(v2.begin(), v2.end(), MyPrint());
}
//find
void test3()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>::iterator pos = find(v1.begin(), v1.end(), 2);
	if (pos != v1.end())
	{
		cout << "找到了: " << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}
//类Person find
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
		if (this->name == p.name && this->age == p.age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string name;
	int age;
};

void test4()
{
	vector<Person> v;
	Person p1("tom", 35);
	Person p2("aoom", 33);
	Person p3("giom", 35);
	Person p4("eeom", 33);
	Person p5("wom", 34);
	Person p6("ssom", 35);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	Person pp("tom", 34);
	vector<Person>::iterator pos = find(v.begin(), v.end(), pp);
	if (pos != v.end())
	{
		cout << "找到了:  姓名: " << pos->name << " 年龄: " << pos->age << endl;
	}
	else
	{
		cout << "未找到" << endl; 
	}
}
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
//find_if
void test5()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>::iterator pos = find_if(v1.begin(), v1.end(), GreaterFive());
	if (pos != v1.end())
	{
		cout << "找到了: " << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}
class PersonCompare
{
public:
	bool operator()(const Person& p)
	{
		return p.age > 20;
	}
};
//Person find_if
void test6()
{
	vector<Person> v1;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 10);
	Person p5("eee", 30);
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);
	vector<Person>::iterator pos = find_if(v1.begin(), v1.end(), PersonCompare());
	if (pos != v1.end())
	{
		cout << "找到了:  姓名: " << pos->name << " 年龄: " << pos->age << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}
//adjacent_find
void test7()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(3);
	v1.push_back(3);
	vector<int>::iterator pos = adjacent_find(v1.begin(), v1.end());
	if (pos != v1.end())
	{
		cout << "找到了: " << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}
//binary_search
void test8()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	bool ret = binary_search(v1.begin(), v1.end(), 10);
	if (ret)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	test8();
	return 0;
}
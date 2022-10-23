#include<iostream>
using namespace std;
#include<set>
void myprint(set<int> s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	myprint(s1);
	set<int> s2(s1);
	set<int> s3;
	s3 = s1;
	myprint(s2);
	myprint(s3);
}
void test2()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	if (s1.empty())
	{
		cout << "s1为空" << endl;
	}
	else
	{
		cout << s1.size() << endl;
	}
	set<int> s2;
	s2.insert(69);
	s2.insert(50);
	s2.insert(70);
	s2.insert(80);
	s1.swap(s2);
	myprint(s1);
	myprint(s2);
}
void test3()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	myprint(s1);
	s1.erase(s1.begin());
	myprint(s1);
	s1.erase(30);
	myprint(s1);
	//s1.erase(s1.begin(),s1.end());
	s1.clear();
	myprint(s1);
}
void test4()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	set<int>::iterator pos = s1.find(10);
	if (pos != s1.end())
	{
		cout << "找到了:" << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
	int num = 0;
	num=(int)s1.count(30);
	cout << num << endl;
}
void test5()
{
	set<int> s1;
	pair<set<int>::iterator, bool> ret = s1.insert(10);
	if (ret.second)
	{
		cout << "第一次插入成功" << endl;
	}
	else
	{
		cout << "第一次插入失败" << endl;
	}
	ret = s1.insert(10);
	if (ret.second)
	{
		cout << "第二次插入成功" << endl;
	}
	else
	{
		cout << "第二次插入失败" << endl;
	}
	multiset<int> ms;
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test6()
{
	pair<string, int> p(make_pair("jerry", 20));
	cout << "姓名:" << p.first << "\t年龄:" << p.second << endl;
	pair<string, int> p1(string("tom"), 20);
	cout << "姓名:" << p1.first << "\t年龄:" << p1.second << endl;

}
class my_compare
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};
void test7()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	s1.insert(50);
	myprint(s1);
	set<int, my_compare> s2;
	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	s2.insert(50);
	for (set<int, my_compare>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
class person
{
public:
	person(string name,int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};
class personcompare
{
public:
	bool operator()(const person& p1, const person& p2)const
	{
		return p1.age > p2.age;
	}
};
void test8()
{
	set<person, personcompare> s;
	person p1("刘备", 43);
	person p2("张飞", 23);
	person p3("关羽", 21);
	person p4("孙策", 35);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	for (set<person, personcompare>::iterator it=s.begin();it!=s.end();it++)
	{
		cout << it->name << it->age << "岁" << endl;
	}
	cout << endl;
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
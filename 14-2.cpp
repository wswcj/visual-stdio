#include<iostream>
#include<map>
using namespace std;
void printmap(map<int, int> m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key=" << it->first << "\tvalue=" << it->second << endl;
	}
}
void test1()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(3, 20));
	m.insert(pair<int, int>(2, 30));
	m.insert(pair<int, int>(4, 40));
	printmap(m);
	map<int, int> m1 = m;
	map<int, int>m2;
	m2 = m;
	printmap(m1);
	printmap(m2);
}
void test2()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(3, 20));
	m.insert(pair<int, int>(2, 30));
	m.insert(pair<int, int>(4, 40));
	if (m.empty())
	{
		cout << "m为空" << endl;
	}
	else
	{
		cout << "size=" << m.size() << endl;
	}
	map<int, int> m1;
	m1.insert(pair<int, int>(5, 10));
	m1.insert(pair<int, int>(6, 20));
	m1.insert(pair<int, int>(7, 30));
	m1.insert(pair<int, int>(8, 40));
	m.swap(m1);
	printmap(m);
}
void test3()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;
	printmap(m);
	cout << endl;
	m.erase(m.begin());
	printmap(m);
	cout << endl;
	m.erase(3);
	printmap(m);
	cout << endl;
	//m.erase(m.begin(), m.end());
	m.clear();
	printmap(m);
}
void test4()
{
	map<int, int> m1;
	m1.insert(make_pair(1, 10));
	m1.insert(make_pair(2, 20));
	m1.insert(make_pair(3, 30));
	m1.insert(make_pair(4, 40));
	map<int, int>::iterator pos = m1.find(1);
	if (pos != m1.end())
	{
		cout << "找到了key=" << pos->first << "\tvalue=" << pos->second << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
	int num = m1.count(1);
	cout << num;
}
class my_compare
{
public:
	bool operator()(int v1,int v2)const
	{
		return v1 > v2;
	}
};
void test5()
{
	map<int, int, my_compare> m1;
	m1.insert(make_pair(1, 10));
	m1.insert(make_pair(3, 30));
	m1.insert(make_pair(2, 20));
	m1.insert(make_pair(4, 40));
	for (map<int, int, my_compare>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << "key=" << it->first << "\tvlaue=" << it->second << endl;
	}
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}
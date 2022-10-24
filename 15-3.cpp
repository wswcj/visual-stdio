#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
void test1()
{
	//plus
	plus<int> p1;
	cout << p1(10, 10) << endl;
	//minus
	minus<int> m1;
	cout << m1(20, 10) << endl;
	//multiplies
	multiplies<int> mul1;
	cout << mul1(10, 10) << endl;
	//divides
	divides<int> d1;
	cout << d1(100, 10) << endl;
	//modulus
	modulus<int> mo1;
	cout << mo1(100, 10) << endl;
	//negate
	negate<int> n1;
	cout << n1(10) << endl;
}
void test2()
{
	//greater
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test3()
{
	vector<bool> v1;
	v1.push_back(false);
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	for (vector<bool>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	vector<bool> v2;
	v2.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}
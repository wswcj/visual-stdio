#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class greaterfive
{
public:
	bool operator()(int v1)
	{
		return v1 > 5;
	}
};
void test1()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), greaterfive());
		if (it != v.end())
		{
			cout << "找到了: " << *it << endl;
		}
		else
		{
			cout << "未找到" << endl;
		}
}
class mycompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test2()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	sort(v.begin(), v.end(), mycompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	//test1();
	test2();
	return 0;
}
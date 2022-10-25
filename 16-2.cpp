#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>
#include<ctime>
using namespace std;
class MyPrint
{
public:
	void operator()(int v1)
	{
		cout << v1 << " ";
	}
};
//sort
void test1()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	sort(v1.begin(), v1.end(), greater<int>());
	for_each(v1.begin(), v1.end(), MyPrint());
}
//random_shuffle
void test2()
{
	srand((unsigned int)time(NULL));
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	random_shuffle(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
}
//merge
void test3()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
	}
	vector<int>target;
	target.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
	for_each(target.begin(), target.end(), MyPrint());
	cout << endl;
}
//reverse 反转
//copy 拷贝
//replace
void test4()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(20);
	v1.push_back(40);
	v1.push_back(30);
	v1.push_back(20);
	replace(v1.begin(), v1.end(), 20, 2000);
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
}
class Greater20
{
public:
	bool operator()(int v1)
	{
		return v1 > 20;
	}
};
//replace_if
void test5()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(20);
	v1.push_back(40);
	v1.push_back(30);
	v1.push_back(20);
	replace_if(v1.begin(), v1.end(), Greater20(),3000);
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
}
//swap swap(v1,v2) 交换
//accumulate
void test6()
{
	vector<int> v1;
	for (int i = 1; i <= 100; i++)
	{
		v1.push_back(i);
	}
	int total = accumulate(v1.begin(), v1.end(),0);
	cout << total << endl;
}
//fill
void test7()
{
	vector<int> v1;
	v1.resize(10);
	fill(v1.begin(), v1.end(), 100);
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
}
//set_intersection
void test8()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int> target;
	target.resize(min(v1.size(), v2.size()));
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
	for_each(target.begin(), itEnd, MyPrint());
	cout << endl;
}
//set_union
void test9()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int> target;
	target.resize(v1.size() + v2.size());
	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
	for_each(target.begin(), itEnd, MyPrint());
	cout << endl;
}
//set_diference
void test10()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	vector<int> target;
	target.resize(max(v1.size(), v2.size()));
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
	cout << "v1和v2相比:" << endl;
	for_each(target.begin(), itEnd, MyPrint());
	cout << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), target.begin());
	cout << "v2和v1相比:" << endl;
	for_each(target.begin(), itEnd, MyPrint());
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
	//test8();
	//test9();
	test10();
	return 0;
}
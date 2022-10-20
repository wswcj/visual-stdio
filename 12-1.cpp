#include<iostream>
#include<vector>
using namespace std;

void printvector(vector<int> v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl;
}

void test1()
{
	vector<int> v1;
	for (int i = 1; i < 10; i++)
	{
		v1.push_back(i);
	}
	printvector(v1);
	cout << endl;
	vector<int> v2(v1.begin(), v1.end());
	printvector(v2);
	cout << endl;
	vector<int> v3(10, 100);
	printvector(v3);
	cout << endl;
	vector<int> v4(v3);
	printvector(v4);
}
void test2()
{
	vector<int> v1;
	for (int i = 1; i < 10; i++)
	{
		v1.push_back(i);
	}
	printvector(v1);
	cout << endl;
	vector<int> v2;
	v2 = v1;
	printvector(v2);
	cout << endl;
	vector<int> v3;
	v3.assign(v1.begin(), v1.end());
	printvector(v3);
	cout << endl;
	vector<int> v4;
	v4.assign(10, 100);
	printvector(v4);
}
void test3()
{
	vector<int> v1;
	for (int i = 1; i <= 10; i++)
	{
		v1.push_back(i);
	}
	printvector(v1);
	if (v1.empty())
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "容量:" << v1.capacity() << endl;
		cout << "大小:" << v1.size() << endl;
	}
	v1.resize(15, 11);
	printvector(v1);
	v1.resize(8);
	printvector(v1);
}
void test4()
{
	vector<int> v1;
	for (int i = 1; i < 10; i++)
	{
		v1.push_back(i);
	}
	printvector(v1);
	v1.pop_back();
	printvector(v1);
	v1.push_back(9);
	v1.insert(v1.begin(), 100);
	printvector(v1);
	v1.insert(v1.begin(), 2, 1000);
	printvector(v1);
	v1.erase(v1.begin());
	printvector(v1);
	v1.clear();
	printvector(v1);

}
void test5()
{
	vector<int> v1;
	for (int i = 1; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;
	cout << v1.front() << endl;
	cout << v1.back() << endl;
}
void test6()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (int i = 9; i >= 0; i--)
	{
		v2.push_back(i);
	}
	printvector(v1);
	printvector(v2);
	v1.swap(v2);
	cout << "交换后:" << endl;
	printvector(v1);
	printvector(v2);
}
void test7()
{
	vector<int> v1;
	for (int i = 0; i < 1000; i++)
		v1.push_back(i);
	cout << v1.capacity() << endl;
	v1.resize(3);
	cout << v1.capacity() << endl;
	vector<int>(v1).swap(v1);
	cout << v1.capacity() << endl;
}
void test8()
{
	vector<int> v;
	v.reserve(10000);
	int count = 0;
	int* p = NULL;
	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			count++;
		}
	}
	cout << count << endl;
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
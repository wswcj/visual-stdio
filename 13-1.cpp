#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>
void my_print(deque<int> &d)
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	deque<int> d1(10, 10);
	my_print(d1);
	deque<int> d2(d1.begin(), d1.end());
	my_print(d2);
	deque<int> d3;
	d3.assign(10, 10);
	my_print(d3);
	deque<int> d4;
	d4.assign(d3.begin(), d3.end());
	my_print(d4);

}
void test2()
{
	deque<int> d1;
	d1.push_back(30);
	d1.push_back(40);
	d1.push_front(20);
	d1.push_front(10);
	my_print(d1);
	if (d1.empty())
	{
		cout << "d1为空" << endl;
	}
	else
	{
		cout << "d1的个数为" << d1.size() << endl;
	}
	d1.resize(10);
	my_print(d1);
	d1.resize(2);
	my_print(d1);
}
void test3()
{
	deque<int> d1;
	d1.push_back(30);
	d1.push_back(40);
	d1.push_front(20);
	d1.push_front(10);
	d1.insert(d1.begin(), 100);
	d1.pop_front();
	my_print(d1);
	/*d1.pop_back();
	my_print(d1);*/
	deque<int> d2;
	d2.push_back(10);
	d2.push_back(10);
	d2.push_back(10);
	d2.push_back(10);
	d1.insert(d1.begin(), d2.begin(), d2.end());
	my_print(d1);
	d1.erase(d1.begin());
	d1.erase(d1.begin());
	d1.erase(d1.begin());
	d1.erase(d1.begin());
	my_print(d1);
	//d1.erase(d1.begin(), d1.end());
	//my_print(d1);
	d1.clear();
	my_print(d1);
}
void test4()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);

	}
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << d1.at(i) << endl;
	}
	cout << d1.front() << endl;
	cout << d1.back() << endl;
}
void test5()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(30);
	d1.push_back(40);
	d1.push_back(20);
	my_print(d1);
	sort(d1.begin(), d1.end());
	my_print(d1);
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
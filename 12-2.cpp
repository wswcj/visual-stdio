#include<iostream>
#include<deque>
using namespace std;
void printdeque(const deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test()
{
	deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
		d.push_front(i);
	}
	printdeque(d);
}
int main()
{
	test();
	return 0;
}
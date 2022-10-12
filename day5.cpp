#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
void test1()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	vector<int>::iterator pBegin = v.begin();
	vector<int>::iterator pEnd = v.end();
	while (pBegin != pEnd)
	{
		cout << *pBegin << endl;
		pBegin++;
	}
}
int main()
{
	test1();
}
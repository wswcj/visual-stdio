#include<iostream>
#include<list>
using namespace std;
bool mycompare(int val1,int val2)
{
	return val1 > val2;
}
void my_print(list<int>& L)
{
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	list<int> L2(L1.begin(), L1.end());
	my_print(L2);
	list<int> L3(10.10);
	my_print(L3);
	list<int> L4;
	L4.push_back(40);
	L4.push_back(30);
	L4.push_back(20);
	L4.push_back(10);
	cout << "L1:" << endl;
	my_print(L1);
	cout << "L4:" << endl;
	my_print(L4);
	L1.swap(L4);
	cout << "交换后:" << endl;
	cout << "L1:" << endl;
	my_print(L1);
	cout << "L4:" << endl;
	my_print(L4);
}
void test2()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.insert(L1.begin(), 9);
	my_print(L1);
	list<int>::iterator it = L1.begin();
	L1.insert(++(++it), 11);
	my_print(L1);
	L1.push_back(10000);
	L1.push_back(10000);
	L1.push_back(10000);
	my_print(L1);
	L1.remove(10000);
	my_print(L1);
	cout << L1.front() <<"\t" << L1.back() << endl;
	L1.clear();
}
void test3()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(30);
	L1.push_back(20);
	L1.push_back(40);
	my_print(L1);
	L1.reverse();
	my_print(L1);
	L1.sort();
	my_print(L1);
	L1.sort(mycompare);
	my_print(L1);
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}
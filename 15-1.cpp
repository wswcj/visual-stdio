#include<iostream>
using namespace std;
class myadd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};
class myprint
{
public:
	myprint()
	{
		count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		count++;
	}
	int count;
};
void test1()
{
	myadd myadd1;
	cout << myadd1(10, 10) << endl;
}
void doprint(myprint& mp, string test)
{
	mp(test);
}
void test2()
{
	myprint mp;
	mp("hello world");
	mp("hello world");
	mp("hello world");
	mp("hello world");
	cout << mp.count << endl;
}
void test3()
{
	myprint mp;
	doprint(mp, "hello world");

}

int main()
{
	//test1();
	//test2();
	//test3();
	return 0;
}
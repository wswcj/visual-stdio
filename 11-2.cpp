#include<iostream>
using namespace std;
template<class t>
class father
{
	t a;
};
template<class t1,class t2>
class son: public father<t2>
{
public:
	son()
	{
		cout << typeid(t1).name() << endl;
		cout << typeid(t2).name() << endl;
	}
};
void test()
{
	son<int, char> son1;
}
int main()
{
	test();
	return 0;
}
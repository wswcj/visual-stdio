#include<iostream>
#include<stack>
#include<queue>

using namespace std;
class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};
void test1()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	cout << s.size() << endl;
}
void test2()
{
	queue<Person> q;
	Person p1("孙悟空", 2000);
	Person p2("唐僧", 20);
	Person p3("猪八戒", 1000);
	Person p4("沙悟净", 900);
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	while (!q.empty())
	{
		cout << q.front().name << q.front().age << "岁" << endl;
		cout << q.back().name << q.back().age << "岁" << endl;
		q.pop();
	}
	q.size();
}
int main()
{
	//test1();
	test2();
	return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<map>
#include<stack>
#include<list>
#include<set>
using namespace std;
void myPrint(int val) {
	cout << val << " ";
}
void test1() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i * 10);
	}
	for_each(v1.begin(), v1.end(), myPrint);
}
void test2() {
	string str1;
	str1.assign("helloworld", 5);
	cout << str1 << endl;
	//string str2.assign(5, 'x');错误写法
	string str2;
	str2.assign(5, 'x');
	cout << str2 << endl;
	str1 += str2;
	cout << str1 << endl;
	str1.append("helloworld", 5);
	cout << str1 << endl;
	str1.append("helloworld", 5, 5);
	cout << str1 << endl;
	str1.replace(5, 5, "zzzzz");
	cout << str1 << endl;
	str1.insert(0, "hhhhh");
	cout << str1 << endl;
	str1.erase(0, 5);
	cout << str1 << endl;
}
void test3() {
	string str = "12345678@qq.com";
	int ret = str.find('@');
	string qq;
	qq = str.substr(0, ret);
	cout << qq << endl;
}
void test4() {
	vector<int> v1 = { 11,12,13,14,15 };
	auto it = v1.begin();
	v1.insert(it, 10);
	//v1.erase(v1.rbegin());迭代器不能为rbegin()
	//cout << v1[0] << endl;
	v1.pop_back();
	cout << *v1.rbegin() << endl;
}
void test5() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	cout << *v1.rbegin() << endl;
	reverse(v1.begin(), v1.end());
	cout << *v1.rbegin() << endl;
}
void test6() {
	vector<int> v1(10000, 0);
	cout << v1.capacity() << endl;
	v1.resize(3);
	cout << v1.capacity() << endl;
	vector<int>(v1).swap(v1);
	cout << v1.capacity() << endl;
}
void test7() {
	vector<int> v1;
	v1.reserve(10000);
	int count = 0;
	int* p = NULL;
	for (int i = 0; i < 10000; i++) {
		v1.push_back(i);
		if (p != &v1[0]) {
			p = &v1[0];
			count++;
		}
	}
	cout << count << endl;
}
void test8() {
	deque<int> d1;
	for (int i = 0; i < 10; i++) {
		d1.push_front(i);
	}
	for_each(d1.begin(), d1.end(), myPrint);
	cout << endl;
	sort(d1.begin(), d1.end());
	for_each(d1.begin(), d1.end(), myPrint);
	cout << endl;
	vector<int> v1;
	for (int i = 9; i >= 0; i--) {
		v1.push_back(i);
	}
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;
	sort(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;
}
void test9() {
	stack<int> s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	cout << s1.top() << endl;
	while (!s1.empty()) {
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;
	cout << "size = " << s1.size() << endl;
}
bool myCompare(int v1, int v2) {
	return v1 > v2;
}
void test10() {
	list<int> l1;
	l1.push_back(1);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(2);
	for_each(l1.begin(), l1.end(), myPrint);
	cout << endl;
	l1.sort();
	for_each(l1.begin(), l1.end(), myPrint);
	cout << endl;
	l1.sort(myCompare);
	for_each(l1.begin(), l1.end(), myPrint);
	cout << endl;
}
void test11() {
	set<int> s1;
	pair<set<int>::iterator, bool> ret = s1.insert(10);
	if (ret.second) {
		cout << "第一次插入成功" << endl;
	}
	else {
		cout << "第二次插入失败" << endl;
	}
	ret = s1.insert(10);
	if (ret.second) {
		cout << "第一次插入成功" << endl;
	}
	else {
		cout << "第二次插入失败" << endl;
	}
}
void test12() {
	pair<string, int> p1 = make_pair("tom", 20);
	cout << "姓名: " << p1.first << " 年龄: " << p1.second << endl;
}
class My_Compare {
public:
	bool operator()(int v1, int v2) const{
		return v1 > v2;
	}
};
void test13() {
	set<int, My_Compare> s1;
	s1.insert(1);
	s1.insert(6);
	s1.insert(2);
	s1.insert(5);
	s1.insert(3);
	for_each(s1.begin(), s1.end(), myPrint);
	cout << endl;
}
class Person {
public:
	int age;
	string name;
};
class my_compare {
public:
	bool operator()(const Person& p1, const Person& p2) const {
		return p1.age > p2.age;
	}
};
void my_Print(const Person& p) {
	cout << "姓名: " << p.name << " 年龄: " << p.age << endl;
}
void test14() {
	set<Person, my_compare> s1;
	Person p1 = { 20, "tom" };
	Person p2 = { 10, "tom" };
	Person p3 = { 40, "tom" };
	Person p4 = { 50, "tom" };
	Person p5 = { 60, "tom" };
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	s1.insert(p5);
	for_each(s1.begin(), s1.end(), my_Print);
	cout << endl;
}
void My_print(pair<int, int> p1) {
	cout << "key = " << p1.first << " value = " << p1.second << endl;
}
class mycompare {
public:
	bool operator()(int v1, int v2) const {
		return v1 > v2;
	}
};
void test15() {
	map<int, int> m1;
	m1.insert(make_pair(1, 10));
	m1.insert(make_pair(2, 20));
	m1.insert(make_pair(3, 30));
	m1.insert(make_pair(4, 40));
	m1.insert(make_pair(5, 50));
	for_each(m1.begin(), m1.end(), My_print);
	auto it = m1.find(2);
	if (it != m1.end()) {
		cout << "找到了key = " << it->first << endl;
	}
	int num = m1.count(2);
	cout << "num = " << num << endl;
	map<int, int, mycompare> m2;
	m2.insert(make_pair(1, 10));
	m2.insert(make_pair(2, 20));
	m2.insert(make_pair(3, 30));
	m2.insert(make_pair(4, 40));
	m2.insert(make_pair(5, 50));
	for_each(m2.begin(), m2.end(), My_print);
}
int main() {
	test15();
	return 0;
}
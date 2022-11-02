#include<iostream>
#include<vector>
#include<map>
using namespace std;
void test1() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	for (int i : v1) {
		cout << i << " ";
	}
}
void test2() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	for (auto i : v1) {
		cout << i << " ";
	}
	cout << endl;
	auto it = v1.begin();
	cout << *it << endl;
}
void test3() {
	auto age = 100;
	cout << age << endl;
	auto name = "ss";
	cout << name << endl;
}
void test4() {
	map<int, int> m;
	m[1] = 1;
	m.insert(2, 2);
	auto it = m.begin();
	auto it1 = m.end();
	//cout << it->second << endl;
	cout << m[1] << endl;
}
int main() {
	test4();
	return 0;
}
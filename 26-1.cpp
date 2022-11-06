#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>
void myPrint(const vector<int>& v)
{
	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}
void test1() {

	vector<int> v1(3, 1);
	v1.insert(v1.begin(), 1, 2);
	myPrint(v1);
	v1.erase(v1.begin());
	myPrint(v1);
	for (int i = 0; i < 1000; i++) {
		v1.push_back(i);
	}
	cout << v1.capacity() << endl;
	v1.resize(10);
	cout << v1.capacity() << endl;
	vector<int>(v1).swap(v1);
	cout << v1.capacity() << endl;
	vector<int> v2;
	v2.reserve(1000);
	cout << v2.capacity() << endl;
	v2.resize(10);
	cout << v2.capacity() << endl;
	vector<int>(v2).swap(v2);
	cout << v2.capacity() << endl;
	sort(v1.begin(), v1.end());
	//char c = ""
}
void test2() {
	string str1 = "hello";
	str1.erase(1);
	cout << str1 << endl;
}
void test3() {
	setlocale(LC_ALL, "chs");
	wchar_t wt[] = L"中国伟大复兴梦";
	wcout << wt << endl;
	//extern int i = 1;
}
void test4() {
	char a = 0x81;
	if (a == 0x81) {
		cout << "you are matched!!!" << endl;
	}
	cout << "a is " << (int)a << endl;
	unsigned char w = a;
	cout << "c is " << (int)w << endl;
	extern int num;
	cout << num << endl;
}
int num = 1;
constexpr int* p = &num;
void test5() {
	double dval = 3.14;
	//int* p = &dval;
	//int& a = dval;
}
constexpr int fun(int n) {
	return n;
}
void test6() {
	int m = 0;
	//constexpr int i = fun(m);
	//constexpr int n = m;
	//constexpr int& n = 100;
	//constexpr int* n = &m;
	constexpr int* n = 0;
}
int main() {
	test6();
	//cout << i << endl;
	return 0;
}
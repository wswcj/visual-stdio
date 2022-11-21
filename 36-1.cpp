#include<iostream> 
using namespace std;
void test1() {
	const int val = 6;
	cout << "&val = " << &val << ", val = " << val << endl;
	const int* cp = &val;
	int* p = const_cast<int*>(cp);
	*p = 2;
	cout << "&val = " << &val << ", val = " << val << endl;
	cout << "p = " << p << ", *p = " << *p << endl;
}
void test2() {
	int init = 6;
	const int val = init;//和上面代码的区别在这里
	cout << "&val = " << &val << ", val = " << val << endl;
	const int* cp = &val;
	int* p = const_cast<int*>(cp);
	*p = 2;
	cout << "&val = " << &val << ", val = " << val << endl;
	cout << "p = " << p << ", *p = " << *p << endl;
}
const string& shorterString(const string& s1, const string& s2) {
	return s1.size() > s2.size() ? s1 : s2;
}
string& shorterString(string& s1, string& s2) {
	auto& r = shorterString(const_cast<const string&> (s1), const_cast<const string&>(s2));
	return const_cast<string&> (r);
}
string read();
void print(const string&);
void print(double);
void fooBar(int ival) {
	bool read = false;//隐藏了外层的read()
	//string s = read();
	void print(int);//同上
	//print("value: ");
	//print(3.13);
}
typedef string::size_type sz;
string screen(sz, sz, char = ' ');
//string screen(sz, sz, char = '*');
string screen(sz = 24, sz = 80, char);//正确的
void test3() {
	cout << endl;
}
int main() {
	test3();
	return 0;
}
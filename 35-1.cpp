#include<iostream> 
#include<stdlib.h>
#include<vector>
#include<map>
using namespace std;
#define SUM(x) x * x
#define SUM1(x) (x) * (x)
vector<vector<int>> test1() {
	//我认为很秀的操作
	vector<vector<int>> ans;
	ans.push_back(vector<int>());//先插入一个vector空容器
	int val = 1;
	ans.back().push_back(val);//然后再插入数
	return ans;
}
template<class T1, class T2>
auto add3(T1&& a, T2&& b) {
	return a + b;
}
void test2() {
	int i = 1, j = 2;
	int sum = add3(i, j);
	cout << sum << endl;
	sum = add3(1, 3);//用右值引用的原因
}
void test3() {
	int i = 10;
	const int& a1 = 10;
	//int&& a2 = a1;err
	int& a2 = i;
	//int&& a3 = a2;err因为右值引用的右边一定是一个右值
	int&& a3 = 10;
}
int Plus(int i, int j) {
	return i + j;
}
int Minus(int i, int j) {
	return i - j;
}
int Divides(int i, int j) {
	return i / j;
}
int Multiplies(int i, int j) {
	return i * j;
}
void test4() {
	int (*f)(int, int) = nullptr;//函数指针
	f = Plus;
	f = &Plus;//等价的
	int t1 = Plus(1, 3);
	int t2 = f(1, 3);
}
void test5() {
	int(*v[4])(int, int);//函数指针数组
	vector<int(*)(int, int)> v1;
	map<int, int(*)(int, int)> m;
	using pf = int(*)(int, int);//等价的
	vector<pf> v2;
	map<int, pf> m1;
	pf f[4];
}
void test6() {
	int a, b, c;
	cin >> a >> b >> c;
	using pf = int(*)(int, int);
	map<int, pf> m = {
		{0, Plus}, {1, Minus}, {2, Divides}, {3, Multiplies}
	};
	cout << m[c](a, b) << endl;//c是用来选择操作的,a和b是操作数
}
void test7() {
	//[捕获列表](参数列表)->返回类型{函数体}
	//其中参数列表,箭头和返回类型可以省略但必须永远包含捕获列表和函数体
	int(*f)(int, int) = [](int a, int b) { return a + b; };
	auto f1 = [](int a, int b) { return a + b; };
	cout << f(1, 2) << endl;
}
void test8() {
	int a, b, c;
	cin >> a >> b >> c;
	using pf = int(*)(int, int);
	map<int, pf> m = {
		{0, [](int a, int b) { return a + b; }},
		{1, [](int a, int b) { return a - b; }},
		{2, [](int a, int b) { return a * b; }},
		{3, [](int a, int b) { return a / b; }}
	};
	m.insert({ 4, [](int a, int b) { return a % b; } });
	cout << m[c](a, b) << endl;
}
inline int fun(int x) {//内联函数(类内定义的函数都是内联函数)
	return x * x;
}
void test9() {
	int a = fun(2 + 3);//执行5 * 5
	int b = SUM(2 + 3);//执行2 + 3 * 2 + 3
	int c = SUM1(2 + 3);//执行(2 + 3) * (2 + 3)
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}
void test9() {
	size_t a = 5;
	//ssize_t b = -5;
}
int main() {
	test8();
	return 0;
}
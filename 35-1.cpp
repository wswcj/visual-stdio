#include<iostream> 
#include<stdlib.h>
#include<vector>
#include<functional>
#include<algorithm>
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
		{0, [](int a, int b)->int { return a + b; }},
		{1, [](int a, int b) { return a - b; }},
		{2, [](int a, int b) { return a * b; }},
		{3, [](int a, int b) { return a / b; }}
	};
	m.insert({ 4, [](int a, int b) { return a % b; } });
	cout << m[c](a, b) << endl;
}
void test12() {//头文件functional
	function<int(int, int)>f1 = [](int a, int b) { return a + b; };//注意没有*号
	function<int(int, int)>f2 = Plus;//同上

}
void test13() {
	int a, b, c;
	cin >> a >> b >> c;
	using pf = int(int, int);//注意没有分号
	map<int, function<pf>> m = {
		{0, [](int a, int b) { return a + b; } },
		{1, [](int a, int b) { return a - b; } },
		{2, [](int a, int b) { return a * b; } },
		{3, [](int a, int b) { return a / b; } }
	};
	m.insert({ 4, [](int a, int b) { return a % b; } });
	cout << m[c](a, b) << endl;
}
using pf = function<int(int, int)>;//pf 是该函数指针类型的别名
pf g() {
	return Plus;
}
pf h() {
	return [](int a, int b) { return a + b; };
}
void test14() {
	auto i = g();
	cout << i(1, 2) << endl;
	auto j = h();
	cout << j(1, 2) << endl;
}
bool cmp(int a, int b) {
	return a > b;
}
void myPrint(int val) {
	cout << val << " ";
}
void test15() {
	vector<int> v = { 1,2,3,4,5 };
	sort(v.begin(), v.end(), cmp);
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	vector<int> v1 = { 1,2,3,4,5 };
	sort(v.begin(), v.end(), [](int a, int b) { return a > b; });//等价的
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	vector<int> v2 = { 1,2,3,4,5 };
	sort(v.begin(), v.end(), greater<int>());//等价的
}
double compute(double a, double b, function<double(double)> f) {
	return (f(b) + f(a)) * (b - a) / 2;//求一元一次方程的定积分,求区间[a,b]之间的梯形面积
}
void test16() {
	cout << compute(3.0, 7.0, [](double x) { return x + 10.0; }) << endl;//求y = x + 10在[3,7]上的定积分
	cout << compute(-3.0, 7.0, [](double x) { return -3.0 * x + 5.0; }) << endl;//求y = -3.0x + 5.0在[-3,7]上的定积分
}
int test(int a, int b, int c) {//假如a,b都是一致的,只需传入c的值
	return a + b + c;
}
int testForApplication(int c) {
	return test(1, 2, c);//假设a,b的值是1,2
}
function<int(int)>testForApplication1(int a, int b) {
	return [a, b](int c) { return test(a, b, c); };
}
void test17() {
	auto i = testForApplication1(1, 2);
	cout << i(3) << endl;
	cout << i(4) << endl;
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
void test10() {
	size_t a = 5;
	//ssize_t b = -5;
}
auto add4 = [](int a, int b)->decltype(a + b) {
	return a + b;
};//注意分号不要漏
using arrT = int[10];
arrT* func2(int i) {
	int arr[4][10] = { 0 };
	return &arr[3];//返回arr[3]的含有10个整数的数组
}
int(*func(int i))[10];//等价的
auto func(int i)-> int(*)[10];//等价的
//返回指向数组的指针
auto func1(int arr[][3], int n) -> int(*)[3]{
	return &arr[n];
}
void test11() {
	cout << add4(3, 4) << endl;
}
int main() {
	test17();
	return 0;
}
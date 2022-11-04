#include<iostream> 
using namespace std;
typedef double wages;
using elem = int;
using pstring = char*;
void test1() {
	int* a, b;
	b = 2;
	a = &b;
	cout << *a << endl;
	int* c = nullptr;
	int* d = nullptr;
	int** e = &d;
	int*& r = c;
	r = nullptr;
}
int getSize() {
	return 10;
}
void test2() {
	const int a = getSize();
	cout << a << endl;
}
constexpr int func(int n) {
	return n;
}
void test3() {
	int m = 0;
	const int n = 0;
	//constexpr int i = func(m);
	constexpr int j = func(n);
	constexpr int k = func(n + 1);
	int null = 0;
	//int* p = null;
	wages base, * p;
	elem i = 3;
	cout << i << endl;
	const pstring cstr = 0;
	//cstr = 
	const pstring* ps = nullptr;
}
void test4() {
	int i = 0;
	const int j = i;
	const auto pi = &i;
	*pi = 1;
	cout << i << endl;
	//pi = 
	auto pj = &j;
	//*pj = 
	const auto ci = i;
	auto& m = ci, * p = &ci;
	const auto& d = ci;
	auto* a = &ci;
	//*a = 
	//m = 
	//*p =
}
void test5() {
	int x = 0;
	decltype(x) y = 1;
	cout << typeid(y).name() << endl;
	decltype(x + y) z = 0;
	decltype(x++) a = 0;
	cout << x << endl;//x++ 不回被调用
	cout << typeid(z).name() << endl;
	const int& i = x;
	decltype(i) j = x;
	cout << typeid(j).name() << endl;
	const decltype(z)* p = &z;//const int* 
	cout << typeid(p).name() << endl;
	decltype(z)* pi = &z;//pi : int*
	decltype(pi)* pp = &pi;
	cout << typeid(pp).name() << endl;
	int n = 0, m = 0;
	decltype(m + n) c = 0;
	decltype(n = m + n) d = c;
	cout << typeid(d).name() << endl;
	int b = 1, * pb = &b;
	//decltype(*pb) c;  pb int& c;err
}
struct Sales_data {
	string bookno;
	unsigned units_sold = 0;
	double revenue = 0.0;
}; Sales_data;
void test6() {
	/*Sales_data s1;
	cout << s1.units_sold << endl;
	cout << s1.revenue << endl;*/
	Sales_data data1;
	double price = 0;
	cin >> data1.bookno >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;
	Sales_data data2;
	cin >> data2.bookno >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;
	if (data1.bookno == data2.bookno) {
		unsigned totalCnt = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;
		cout << data1.bookno << " " << totalCnt << " " << totalRevenue << " ";
		if (totalCnt != 0) {
			cout << totalRevenue / totalCnt << endl;
		}
		else {
			cout << "(No sales)" << endl;
		}
	}
	else {
		cout << "Data must refer to the same ISBN" << endl;
		//return -1;
	}
	
}
int main() {
	test6();
	return 0;
}
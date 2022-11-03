#include<iostream> 
using namespace std;
#include <locale>           //setlocale函数在locale头文件中定义
void test1() {
	//使用setlocale函数将本机的语言设置为中文简体
		//LC_ALL表示设置所有的选项（包括金融货币、小数点，时间日期格式、语言字符串的使用习惯等），chs表示中文简体
	setlocale(LC_ALL, "chs");
	wchar_t wt[] = L"中国伟大复兴梦";
	wcout << wt << endl;
	unsigned a = 12;
	cout << a << endl;
}
void test2() {
	char a = 0x81;
	if (a == 0x81) {
		cout << "hh" << endl;
	}
}
void test3() {
	unsigned n = 11;
	while (n > 0) {
		--n;
		cout << n << " ";
	}
	cout << endl;
	cout << "helolol oe efaf"
			"fahfakf d" 
			"hasfja" << endl;
	cout << " hejafdk \"helloworld\" " << endl;
	char16_t utf16c = u'好';
	char32_t utf32c = U'好';
	char utf8c = u8'k';
}
void test4() {
	long double ld = 3.1415926;
	//int a(ld), b = { ld };
	int c(ld), d = ld;
	cout << c << endl << d << endl;
	//int i;
	//cout << i << endl;
}
void fun();
void test5() {
	fun();
	extern int num;
	cout << num << endl;
}
int num = 3;
void fun() {
	cout << "fun" << endl;
}
int a;//全局函数的默认初始化为0
int unique = 42;
void test6() {
	cout << unique << endl;
	int unique = 0;
	cout << unique << endl;
	cout << ::unique << endl;
	int n = unique;
	cout << n << endl;
	int m = ::unique;
	cout << m << endl;
}
void test7() {
	double n = 3.1;
	//int& m = n;
	//int* m = &n;
	void* m = &n;
}
int main() {
	test6();
	int b;
	//cout << b << endl;局部变量没有默认声明
	//cout << a << endl;
	return 0;
}
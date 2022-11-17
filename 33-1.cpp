#include<iostream>
using namespace std;
//判断一个数乘以一个数后是否溢出int类型 
void test1() {
	int i = 1;
	if (i > INT_MAX / 10 || i < INT_MIN / 10) {
		cout << "yes" << endl;
	}
	i *= 10;
}
void test1_1() {
	int sum = 10;
	int digit = 1;
	int flag = -1;//符号位
	int i = INT_MIN;//INT_MAX != INT_MAX * (-1)   INT_MIN == INT_MAX * (-1) - 1
	if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && digit > INT_MAX % 10)) {
		cout << (flag == 1 ? INT_MAX : INT_MIN) << endl;
	}
	sum = sum * 10 + digit;
}
//反转整数,注意不要溢出
void test2() {
	int x = 0;
	cin >> x;
	int res = 0;
	while (x) {
		int t = x % 10;
		res = res * 10 + t;
		x /= 10;
	}
	cout << res << endl;
}
void test3() {
	char ch = '0';
	cout << tolower(ch);
}
//while的妙用
void test4() {
	string s = "h .,.ll . e";
	int n = s.length();
	int i = 0, j = n - 1;
	while (i < j && !isalnum(s[i])) {
		++i;
	}
	while (i < j && !isalnum(s[j])) {
		--j;
	}
}
int main() {
	test3();
	int i = 0;
	/*if (i == 1) {
		return EXIT_FAILURE;
	}
	else {
		return EXIT_SUCCESS;
	}*/
	return 0;//没有系统会隐式提供
}
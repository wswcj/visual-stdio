#include<iostream> 
using namespace std;
void test1() {
	string strs = "hello";
	int len = 10;
	int n = strs.length();
	len = min(n, len);//不能把str.length直接写到min函数里因为此类型是size_t
	size_t i = -1;
	cout << i << endl;
}
void test2() {
	string s1 = "hello";
	string s2(s1, 0, 2);
	cout << s2 << endl;
}

int main() {
	return 0;
}
#include<iostream>
#include<ctime>
#pragma warning(disable:4996)//关闭针对特定代码行的警告
using namespace std;
void test1() {
	time_t seconds;
	seconds = time(NULL);
	cout << "自 1970-01-01 起的小时数 = " << seconds / 3600 << endl;
}
void test2() {
	//基于当前系统的当前日期/时间
	time_t now = time(0);
	// 把 now 转换为字符串形式
	char* dt = ctime(&now);
	cout << "本地日期和时间: " << dt << endl;

}
int main() {
	test2();
	return 0;
}
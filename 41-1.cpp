#include<iostream>
#include<ctime>
#include<fstream>
#include<string>
#pragma warning(disable:4996)//关闭针对特定代码行的警告
using namespace std;
//struct tm {
//	int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
//	int tm_min;   // 分，范围从 0 到 59
//	int tm_hour;  // 小时，范围从 0 到 23
//	int tm_mday;  // 一月中的第几天，范围从 1 到 31
//	int tm_mon;   // 月，范围从 0 到 11
//	int tm_year;  // 自 1900 年起的年数
//	int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
//	int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
//	int tm_isdst; // 夏令时
//};
void test1() {
	//time()
	//获取当地时间，返回time_t类型。
	//返回的时间为UTC格林尼治时间1970年1月1日00:00 : 00到当前时刻的时长，时长单位是秒
	time_t seconds;
	seconds = time(NULL);
	cout << "自 1970-01-01 起的小时数 = " << seconds / 3600 << endl;
}
void test2() {
	//基于当前系统的当前日期/时间
	time_t now = time(0);
	// 把 now 转换为字符串形式
	char* dt = ctime(&now);//ctmie 把 time_t 转化为 string
	//本地时间 = UTC时间 + 时区差 此处为东八区 故加8小时
	cout << "本地日期和时间: " << dt << endl;//星期,月份,时间,年份 
	//gmtime 把 UTC time_t 转化为 tm
	tm* gmtm = gmtime(&now);
	dt = asctime(gmtm);//asctime 把 tm 转化为 string
	cout << "UTC 日期和时间: " << dt << endl;

}
void test3() {
	time_t now = time(0);
	//localtime 把 本地时间 time_t 转化为 tm
	tm* ltm = localtime(&now);
	cout << "年: " << 1900 + ltm->tm_year << endl;
	cout << "月: " << 1 + ltm->tm_mon << endl;
	cout << "日: " << ltm->tm_mday << endl;
	cout << "星期: " << ltm->tm_wday << endl;
	cout << "时间: " << ltm->tm_hour << ":";
	cout << ltm->tm_min << ":";
	cout << ltm->tm_sec << endl;
}
//                 使用 cerr 流来显示错误消息，而其他的日志消息则使用 clog 流来输出
void test4() {
	char str[] = "Unabal to read....";
	//cerr
	cerr << "Error message : " << str << endl;
}
void test5() {
	char str[] = "Unable to read....";
	//clog
	clog << "Error message : " << str << endl;
}
//                         修饰符类型
void test6() {
	//修饰符 signed、unsigned、long 和 short 可应用于整型，signed 和 unsigned 可应用于字符型，
	//long 可应用于双精度型。
	//修饰符 signed 和 unsigned 也可以作为 long 或 short 修饰符的前缀。
	unsigned long int a;
	//允许使用速记符号来声明无符号短整数或无符号长整数
	unsigned int b;
	unsigned c;
	//有符号整数和无符号整数修饰符之间的差别
	short int i;
	short unsigned int j;
	//unsigned short int j; 一样的
	j = 50000;//超过了有signed short 的正整数范围
	i = j;
	cout << i << " " << j;

}
void test8() {
	//istream流 
	//cin.getline() 接收一个字符串，可以接收空格并输出
	char m[20];
	cin.getline(m, 5);//接收5个字符到m中，其中最后一个为'\0'，所以只看到4个字符输出；
	cout << m << endl;
}
void test9() {
	//string流
	//getline 接收一个字符串，可以接收空格并输出，需包含“#include<string>”
	string str;
	getline(cin, str);
	cout << str << endl;
}
void test10() {
	//cin 和 getline() 一起用时要注意在getline() 前加上str = "\n", 不然会跳过getline()
	char sex;
	cout << "Please enter a F or M as your sex: ";
	cin >> sex;
	cout << "Your sex is: " << sex << endl;
	string mystr;
	cout << "What's your favorite team? ";
	mystr = "\n";//如果没有这条语句就会跳过getline()
	getline(cin, mystr);
	cout << "I like " << mystr << ".\n";

}
//                            cin.ignore() 
void test11() {
	char str[30];
	cout << "请输入一个字符串: ";
	cin >> str;
	cout << str << endl;
	cout << "请输入任意字符已结束程序" << endl;
	cin.get();//第一个cin.get() 获取到了'\n'
	cin.get();
}
void test12() {
	char str[30];
	cout << "请输入一个字符串: ";
	cin >> str;
	cout << str << endl;
	//用来清除以回车结束的输入缓冲区的内容，消除上一次输入对下一次输入的影响
	//cin.ignore(1024, '\n'), 遇到'\n'终止
	//cin.ignore(1, EOF), 即把EOF前的1个字符清掉
	cin.ignore(1, EOF);//和下面效果一样
	//cin.ignore(100, '\n');
	cout << "请输入任意字符已结束程序" << endl;
	cin.get();
}
//                                  文件操作
void test7() {
	//以写模式打开文件
	char buf[100];
	ofstream fout("fin.txt");
	cout << "Writing to the file" << endl;
	cout << "Enter a string :";
	cin.getline(buf, 100);
	fout << buf << endl;
	fout.close();

	//以读模式打开文件
	ifstream fin("fin.txt");
	if (!fin) {
		cerr << "Error opening file";
		return;
	}
	cout << "Reading from the file" << endl;
	//fin位置会向后走
	//while (fin.getline(buf, sizeof(buf))) {//读取一行    输出一行
	//	cout << buf << endl;
	//}
	
	//while (fin >> buf) {//读取到空格或换行               输出一个字符串
	//	cout << buf << endl; 
	//}
	
	//char c;
	//while ((c = fin.get()) != EOF) {//读取一个字符          输出一行
	//	cout << c;
	//}
	char ch;
	//将文件的写入位置 从 ios::beg （文件开头算起）移动到编号为5 的字节
	//所有编号从 0 开始，因此编号为 5 的字节实际上是第 6 个字节）
	fin.seekg(5L, ios::beg);//L代表long
	fin.get(ch);
	cout << "从开头向后编号为5的字节的字符: " << ch << endl;
	fin.seekg(3L, ios::cur);
	fin.get(ch);
	cout << "从当前(编号6)向后编号为3的字节的字符: " << ch << endl;
	fin.seekg(-3L, ios::end);
	fin.get(ch);
	cout << "从末尾向前编号为3的字节的字符: " << ch << endl;//不知是不是文件末尾有三个无法打印的字符
	//(换行符,换行符,换行符)
	fin.close();

}
int main() {
	test7();
	return 0;
}
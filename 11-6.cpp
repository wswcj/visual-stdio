#include<iostream>
using namespace std;
void test1()
{
	string str = "abcdefg";
	int pos = str.find("de");
	if (pos == -1)
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "pos=" << pos << endl;
	}
	string str1 = "abcdefg";
	str1.replace(1, 3, "1111");
	cout << str1 << endl;
	int pos1 = str1.find("1e");
	if (pos1 == -1)
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "pos1=" << pos1 << endl;
	}
}
void test2()
{
	const char* str = "abcdef";
	cout << str << endl;
	string str1;
	str1.assign("hello world", 7);
	cout << str1 << endl;
	string str2;
	str2.assign(5, 'a');
	cout << str2 << endl;
	string str3 = "i";
	str3.append(" love ");
	str3.append("game abcd", 5);
	str3.append(str2, 0, 5);
	cout << str3 << endl;
}
void test3()
{
	string str1 = "abcde";
	string str2 = "abcde";
	int ret = str1.compare(str2);
	if (ret == 0)
		cout << "等于" << endl;
	else if (ret > 0)
		cout << "大于" << endl;
	else
		cout << "小于" << endl;
}
void test4()
{
	string str = "abcdef";
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
}
void test5()
{
	string str = "hello";
	str.insert(1, "111");
	cout << str << endl;
	str.erase(1, 3);
	cout << str << endl;
}
void test6()
{
	string email = "12345@qq.com";
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << "username is:" << username << endl;
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
	return 0;
}
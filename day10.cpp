#include<iostream>
#include<fstream>
using namespace std;

void test()
{
	ofstream ofs("test.txt", ios::out);
	ofs << "张三" << endl;
	ofs << "男" << endl;
	ofs << "19" << endl;
	ofs.close();
	//写文件
	ifstream ifs("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	/*char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}*/
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}
	*/
	/*char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}*/
	char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}
	ifs.close();
}

class Person
{

public:
	string name;
	int age;
};

void test1()
{
	ofstream ofs("B_test.txt", ios::out | ios::binary);
	Person p = { "张三",20 };
	ofs.write((char*)&p, sizeof(p));
	ofs.close();
	ifstream ifs("B_test.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	Person p1;
	ifs.read((char*)&p1, sizeof(p));
	cout << p1.name << p1.age << endl;
}
int main()
{
	test();
	test1();
	return 0;
}

#include<fstream>
#include<iostream>
#include<string>
using namespace std;
void test1() {
	ofstream ofs;
	ofs.open("text.txt", ios::out);
	ofs << "小明: " << endl << "20岁 " << endl;
	ofs.close();
}
void test2() {
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败 " << endl;
		return;
	}
	//int arr[10] = { 0 };
	char buf[1024] = { 0 };
	while (ifs >> buf) {
		cout << buf << endl;
	}
	ifs.close();
}
class person {
public:
	int age;
	char name[64];
};
void test3() {
	ofstream ofs("person.txt", ios::out | ios::binary);
	person p = { 20, "tom" };
	ofs.write((const char*)&p, sizeof(p));
	ofs.close();
}
void test4() {
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
		return;
	}
	person p;
	ifs.read((char*)&p, sizeof(p));
	cout << "姓名: " << p.name << ", 年龄: " << p.age << "岁" << endl;
	ifs.close();
}
int main() {
	test4();
	return 0;
}
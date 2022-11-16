#include<iostream>
#include<vector>
using namespace std;
void test1() {
	bool b = true;
	bool b1 = -b;
	cout << b1 << endl;
}
void test2() {
	int grade = 91;
	string finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
	cout << finalgrade<< endl;
}
void test3() {
	int  a = 1;
	cout << sizeof(a) << endl;
	sizeof a;
}
void test4() {
	throw runtime_error("data must refer to same ISBN");
}
void test5() {
	int n = 2;
	while (n > 1) {
		n--;
		try {
			throw runtime_error("data must refer to same ISBN");
		}
		catch (runtime_error err) {
			cout << err.what() << "\nTry Again? Enter y or n" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;
		}
	}
}
void test6() {
	vector<vector<int>> line(5, vector<int>(5, 0));
	cout << '5' - '0' << endl;
}
void reset(int*) {
	;
}
void test7() {
	const int ci = 1;
	//reset(&ci);
}
//string find_char(string& s, char c, string& occurs)
string find_char(const string& s, char c, string& occurs) {
	return "hello";
}
void test8() {
	string ctr = "hello";
	find_char("hello World", 'o', ctr);
	int j[2] = { 1,3 };
	//test9(j);
}
void test9(int (&a)[10]) {
	for (auto num : a) {
		cout << num << endl;
	}
}
void error_msg(initializer_list<string> il) {
	for (auto beg = il.begin(); beg != il.end(); ++beg) {
		cout << *beg << " ";
	}
	cout << endl;
}
void test10() {
	string s = "hh";
	string t = "hh";
	if (s != t) {
		error_msg({ "functionX", s, t });
	}
	else {
		error_msg({ "functionX", "okay" });
	}
}
void slf(string, ...) {
	cout << "省略符形参" << endl;
}
void test11() {
	slf("hello", 1, 2, 3, 'c');
}
int main(int argc, char** argv) {
	cout << argv[0] << endl;
	cout << argc - 1 << endl;
	char ch = 'c';
	char* p = &ch;
	argv[1] = p;
	cout << *argv[1] << endl;

	//test6();
	test11();
	return 0;
}
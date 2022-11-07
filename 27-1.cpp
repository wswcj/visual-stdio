#include<iostream> 
#include<string>
#include<vector>
#include<fstream>
using namespace std;
void test1() {
	constexpr int i = 20;
	int m = 1;
	//constexpr int n = m;
	constexpr int j = i;//i和j都是常量表达式

}
void test2() {
	string str;
	//cin >> str;
	//cout << str << endl;
	/*while (cin >> str) {
		cout << str << " ";
	}*/
	/*while (getline(cin, str)) {
		cout << str << endl;
	}*/
	/*setlocale(LC_ALL, "chs");
	wchar_t wt[255] = L"你好中国";
	wcin >> wt;
	wcout << wt << endl;*/
	/*while (getline(cin, str)) {
		if (!str.empty()) {
			cout << str << endl;
		}
	}*/
	string::size_type i = -1;
	cout << i << endl;
}
void test3() {
	vector<int>::size_type n = -1;
	cout << n << endl;
}
void test4() {
	ifstream ifs;
	ifs.open("test.txt", ios::out);
}
void test5() {
	vector<int> v1;
	v1.push_back(10);
	vector<int>::const_iterator it;
	it = v1.begin();
	cout << *it << endl;
	//*it =
	auto it1 = v1.cbegin();
	//*it1 = 
}
void test6() {
	vector<string> text;
	text.push_back("hello");
	text.push_back("");
	text.push_back("world");
	for (auto it = text.cbegin(); it != text.cend() && !it->empty(); it++) {
		cout << *it << endl;
	}
}
int main() {

	test6();
	return 0;
}
#include<iostream>
#include<cctype>
#include <string>
#include<vector>
using namespace std;
void test1() {
	int i = 3;
	int j = 0;
	j += 2 * i;
	cout << j << endl;
}
void test2() {
	string str1 = "";
	str1 += "helloworld";
	cout << str1 << endl;
	str1.append("1234", 0, 2);
	cout << str1 << endl;
	str1.append("345", 2);
	cout << str1 << endl;
	int pos = str1.rfind("12");
	cout << pos << endl;
	str1.replace(5, 5, "11111");
	cout << str1 << endl;
	str1.replace(5, 5, "world");
	cout << str1 << endl;
	str1.insert(0, "111");
	cout << str1 << endl;
	str1.erase(3, 5);
	cout << str1 << endl;
	str1.insert(3, "hello");
	cout << str1 << endl;
	string sub = str1.substr(3, 5);
	cout << sub << endl;

}
void test3() {
	char a = 'a';
	if (isalpha(a)) {
		cout << a << endl;
	}
	string str1 = "12345";
	if (isdigit(str1[0])) {
		cout << str1[0] << endl;
	}
	else {
		cout << "false" << endl;
	}
	char j = '1';//isdigit  是用来判断字符是不是数字
	if (isdigit(j)) {
		cout << j << endl;
	}
	string s1 = "hello";
	string s2 = s1 + "world";
	//string s3 = "hello" + "world";
	string s4 = s1 + " " + "world";
	cout << s4 << endl;
	//string s5 = "hello" + " " + s1;
	string s6;
	cin >> s6;
	cout << s6 << endl;
	/*string s7;
	while (cin >> s7) {
		cout << s7 << endl;
	}*/
	//string line;
	//while (getline(cin, line)) {//string 头文件
	//	cout << line << endl;
	//}
	string line;
	while (getline(cin, line)) {
		if (!line.empty()) {
			cout << line << endl;
		}
	}
}
void test4() {
	string str("hello world!!!");
	for (auto c : str) {
		//cout << c << endl;
	}
	decltype(str.size()) punct_cnt = 0;
	for (auto c : str) {
		if (ispunct(c)) {
			punct_cnt++;
		}
	}
	cout << punct_cnt << " punctuation characters in " << str << endl;
}
void test5() {
	string s("Hello World!!!");
	for (auto& c : s) {
		c = toupper(c);
	}
	cout << s << endl;
	if (!s.empty()) {
		s[0] = tolower(s[0]);
	}
	cout << s << endl;
	//cout << s[-1] << endl; 这里-1是无符号数
}
void test6() {
	string s("Hello world!!!");
	for (decltype(s.size()) index = 0; index < s.size() && !isspace(s[index]); index++) {
		s[index] = toupper(s[index]);
	}
	cout << s << endl;
}
void test7() {
	const string hexdigits = "0123456789ABCDEF";
	cout << "Enter a series of numbers between 0 and 15 " << "separated by spaces. Hit ENTER when finshed: " << endl;
	string result;
	string::size_type n;
	while (cin >> n) {
		if (n < hexdigits.size()) {
			result += hexdigits[n];
		}
	}
	cout << " Your hex number is: " << result << endl;
}
void test8() {
	string::size_type n;
	//cin >> n;
	//cout << n << endl;
	string s;
	//cout << s << endl;
	//cout << s[0] << endl;
	const string s1("Hello world");
	for (auto& c : s1) {
		//c = 
		cout << c << " ";
	}
}
void test9() {
	vector<int> v1(10);
	for (auto i : v1) {
		//cout << i << endl;
	}
	vector<int> v;
	for (auto i : v) {
		cout << i << endl;
	}
	vector<int> v2(v);
	for (auto i : v2) {
		cout << i << endl;
	}
	vector<string> v3 = { 10, "hi" };
	for (auto c : v3) {
		cout << c << " ";
	}
}
void test10() {
	string word;
	vector<string> text;
	while (cin >> word) {
		text.push_back(word);
	}
	for (auto c : text) {
		cout << c << " ";
	}
	vector<int>::size_type n;
}
void test11() {
	vector<int>::size_type n;//unsigned
	cin >> n;
	cout << n << endl;
}
void test12() {
	vector<unsigned> score(11, 0);
	unsigned grade;
	while (cin >> grade) {
		if (grade <= 100) {
			score[grade / 10]++;
		}
	}
	for (auto i : score) {
		cout << i << " ";
	}

}
int main() {
	test12();
	return 0;
}
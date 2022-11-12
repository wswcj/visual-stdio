#include<iostream> 
#include<vector>
using namespace std;

void test1() {
	ptrdiff_t i = -1;//无符号
	cout << i << endl;
	vector<int>::difference_type j = -1;//无符号
	cout << j << endl;
	size_t a = -1;
	cout << a << endl;
}
void test2() {
	char a[] = "helloworld";
	char b[] = "helloworld";
	if (a < b) {//比较的是char*
		cout << a << endl;
	}
	const char i[] = "helloworld";
	const char j[] = "helloworld";
	if (i < j) {
		cout << i << endl;
	}
}
void test3() {
	const char a[] = { 'h','l','l','l','o' };
	const char* b = a;
	while (*b) {//一直输出空字符直到'/0'
		cout << *b << endl;
		b++;
	}
}
void test4() {
	string s = ("hello");
	const char* str = s.c_str();
	//char str1 = s.c_str();const char* 的值无法初始化char*的值
	cout << str << endl;
	const char* str2 = str;
	cout << str2 << endl;
	s = "world";
	cout << str << endl;
	cout << str2 << endl;
}
void test5() {
	int a[10] = { 1,2,3,4,5,6,7,8,9 };
	vector<int> ivec(begin(a), end(a));
	for (int i : ivec) {
		cout << i << " ";
	}
}
void test6() {
	constexpr size_t rowcnt = 3, colcnt = 4;
	int a[rowcnt][colcnt];
	for (size_t i = 0; i != rowcnt; i++) {
		for (size_t j = 0; j != colcnt; j++) {
			a[i][j] = i * colcnt + j;
		}
	}
	int cnt = 0;
	int b[rowcnt][colcnt];
	for (auto& row : b) {
		for (auto& col : row) {
			col = cnt++;
		}
	}
	for (auto& row : a) {//&是为了防止a被自动转换为指针
		for (auto col : row) {
			cout << col << " ";
		}
	}
	cout << endl;
	for (auto& row : b) {
		for (auto col : row) {
			cout << col << " ";
		}
	}
}
void test7() {
	int ia[3][4] = { 0 };
	for (int i = 0; i != 3; i++) {
		for (int j = 0; j != 4; j++) {
			cout << ia[i][j] << ' ';
		}
	}
	cout << endl;
	for (auto p = ia; p != ia + 3; p++) {
		for (auto q = *p; q != *p + 4; q++) {
			cout << *q << " ";
		}
	}
	cout << endl;
	for (auto p = begin(ia); p != end(ia); p++) {
		for (auto q = begin(*p); q != end(*p); q++) {
			cout << *q << " ";
		}
	}
	cout << endl;
	using int_array = int[4];
	//typedef int int_array[4];等价的
	for (int_array* p = ia; p != ia + 3; p++) {
		for (int* q = *p; q != *p + 4; q++) {
			cout << *q << ' ';
		}
	}
}

int main() {
	test7();
	return 0;
}
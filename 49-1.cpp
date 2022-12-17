#include<iostream>
using namespace std;

#define MAX(X, Y) (X > Y ? X : Y)


void test1() {
	cout << MAX(3, 6) << endl;
	cout << max(3, 6) << endl;
}

void test2() {
	/*int ret = 0;
	int ch = 0;
	char password[20] = { 0 };
	cout << "请输入密码：" << endl;
	cin >> password;
	while (getchar() != '\n') {
		;
	}
	cout << "请确认：" << endl;
	ret = getchar();
	if (ret == 'Y') {
		cout << "确认成功" << endl;
	}
	else {
		cout << "确认失败" << endl;
	}*/

	/*int ret = 0;
	int ch = 0;
	char password[20] = { 0 };
	cout << "请输入密码：" << endl;
	cin.getline(password, 20);
	cout << "请确认：" << endl;
	ret = getchar();
	if (ret == 'Y') {
		cout << "确认成功" << endl;
	}
	else {
		cout << "确认失败" << endl;
	}*/

	char password[20] = { 0 };
	cout << "请输入密码：";
	cin.getline(password, 20);
	cout << "请确认： ";
	if (cin.get() == 'Y') {
		cout << "确认成功" << endl;
	}
	else {
		cout << "放弃确认" << endl;
	}
	/*string str;
	cin >> str;
	cout << str << endl;*/
}
void test3() {
	char a;
	char b;
	a = cin.get();
	cin.ignore(100, '\n');
	cin.get(b);
	cout << a << b << endl;
	cin.ignore();
	int i = cin.get();
	cout << i << endl;
	cin.ignore();
	cin.get(a).get(b);
	cout << a << b << endl;
}
void test4() {
	char a;
	while ((a = cin.get()) != EOF) {
		if (a < '0' || a > '9') {
			continue;
		}
		cout << a << " ";
	}
}


//求两数的最大公因数
void test5() {
	int a, b;
	cout << "请输入两个整数：";
	cin >> a >> b;
	cout << "a 的平方根是：" << sqrt(a) << endl;
	int c = 0;
	while (c = a % b) {
		a = b;
		b = c;
	}
	cout << "a 和 b 的最大公因数是：" << b << endl;

}
//求素数
void test6() {
	int j = 0;
	for (int i = 9; i < 26; ++i) {
		for (j = 2; j <= sqrt(i); ++j) {
			if (i % j == 0) {
				break;
			}
		}
		if (j > sqrt(i)) {
			cout << i << "是质数" << endl;
		}
	}
}
int my_strlen(char* ch) {
	if (*ch == '\0') {
		return 0;
	}
	return 1 + my_strlen(ch + 1);
}
void test7() {
	char arr[] = "hello world";
	cout << my_strlen(arr) << endl;
}
int F(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1 || n == 2) {
		return 1;
	}
	return F(n - 1) + F(n - 2);
}
int F1(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1 || n == 2) {
		return 1;
	}
	int a = 1, b = 1, c = 0;
	for (int i = 3; i < n; ++i) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}
void test8() {
	int num = 0;
	cin >> num;
	int count = 0;
	while (num) {
		if (num % 2 == 1) {
			count++;
		}
		num /= 2;
	}
	cout << count << endl;
}
void test9() {
	int num = 0;
	cin >> num;
	int count = 0;
	for (int i = 0; i < 32; ++i) {
		if (1 == ((num >> i) & 1)) {
			count++;
		}
	}
	cout << count << endl;
}
void test10() {
	int a = 11;
	a = a | (1 << 2);
	cout << a << endl;
	a = a & (~(1 << 2));
	cout << a << endl;
}

void test11() {

	int a = 1, b = 1, c = 2;
	int i = a++ && ++b && c++;
	cout << i << " " << a << " " << b << " " << c << endl;
}
int main() {
	test11();
	return 0;
}
#include<iostream>
#include <chrono>
#include<thread>
#include<vector>
using namespace std::chrono;
using namespace std;
//n^2
void function1(long long n) {
	long long k = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			++k;
		}
	}
}
//nlogn
void function2(long long n) {
	long long k = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < n; j *= 2) {
			++k;
		}
	}
}
//n
void function3(long long n) {
	long long k = 0;
	for (int i = 0; i < n; ++i) {
		++k;
	}
}
//logn
void function4(long long n) {
	long long k = 0;
	for (int i = 1; i < n; i *= 2) {
		++k;
	}
}
void test1() {
	long long n;
	while (1) {
		cout << "Enter a num: ";
		cin >> n;
		milliseconds start_time = duration_cast<milliseconds>(
			system_clock::now().time_since_epoch()
			);
		function4(n);
		milliseconds end_time = duration_cast<milliseconds> (
			system_clock::now().time_since_epoch()
			);
		cout << "耗时: " << milliseconds(end_time).count() - milliseconds(start_time).count() << " ms" << endl;
	}
	
}
long long  func1(int x, int n) {
	int sum = 1;//注意: 任何数的0次方为1
	for (int i = 1; i <= n; ++i) {
		sum *= x;
	}
	return sum;
}
long long func2(int x, int n) {
	if (n == 0) {
		return 1;
	}
	return func2(x, n - 1) * x;
}
long long func3(int x, int n) {
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 1) {
		return func3(x, n / 2) * func3(x, n / 2) * x;
	}
	return func3(x, n / 2) * func3(x, n / 2);
}
long long  func4(int x, long long n) {
	if (n == 0) {
		return 1;
	}
	long long t = func4(x, n / 2);
	if (n % 2 == 1) {
		return t * t * x;	
	}
	return t * t;
}
void test2() {
	int n;
	int x;
	cout << "Enter a num: ";
	cin >> x;
	cout << "Enter a num: ";
	cin >> n;
	cout << x << "的" << n << "次方根是: " << func4(x, n) << endl;
	//cout << INT_MAX << endl;// 约2000000000
	/*long long a = 200000000000;
	cout << a << endl;*/
}	
void test3() {
	int x;
	long long  n;
	cout << "Enter a num: ";
	cin >> x;
	cout << "Enter a num: ";
	cin >> n;
	milliseconds start_time = duration_cast<milliseconds>(
		system_clock::now().time_since_epoch()
		);
	func4(x, n);
	milliseconds end_time = duration_cast<milliseconds>(
		system_clock::now().time_since_epoch()
		);
	cout << "time: " << milliseconds(end_time).count() - milliseconds(start_time).count() << " ms" << endl;

}
int main() {
	test3();
	return 0;
}
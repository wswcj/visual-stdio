#include<iostream>
#include<vector>
using namespace std;
void test1() {
	string str1 = "hello world hello world";
	//str1.replaceAll java 的函数
}
void test2() {
	vector<int> v1;
	for (int i = 0; i < 11; i++) {
		v1.push_back(i);
	}
	auto beg = v1.begin(), end = v1.end();
	auto mid = v1.begin() + (end - beg) / 2;
	while (beg < end ) {
		if (*mid > 6) {
			end = mid;
		}
		else if (*mid < 6) {
			beg = mid + 1;
		}
		else {
			break;
		}
		mid = beg + (end - beg) / 2;
	}
	if (beg < end) {
		cout << "找到了，是： " << *mid << endl;
	}
	else {
		cout << "没找到" << endl;
	}
}
void test3() {
	constexpr int i = 9;
	constexpr int j = i;
	const int n = 1;
	constexpr int m = n;
	int arr1[i];
	int arr2[j];
	int arr3[n];
}
int main() {
	test3();
	return 0;
}
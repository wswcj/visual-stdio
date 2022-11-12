#include<iostream>
#include<vector>
using namespace std;
//int txt_size();
void test1() {

	unsigned buf_size = 1024;
	//int ia[buf_size];
	int ia[4 * 7 - 14];
	//int ia1[txt_size()];
}
int ia[10];
string sa[10];
void test2() {
	int ia1[10];
	string sa1[10];
	cout << ia[1] << endl;
	cout << sa[1] << endl;
	//cout << ia1[1] << endl;
	cout << sa1[1] << endl;
	size_t i = -1;
	cout << i << endl;
}
void test3() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	decltype(arr) arr1 = { 1,2,3,4,5,6,7,8,9,0 };
	for (int i : arr1) {
		cout << i << " ";
	}
	cout << endl;
	int* beg = begin(arr);
	int* last = end(arr);
	//int* end = end(arr);err
	ptrdiff_t i = -1;
	cout << i << endl;
	vector<int>::difference_type j = -1;
	cout << j << endl;
}
void test4() {
	int* p1 = nullptr;
	int* p2 = nullptr;
	p1 += 0;
	p1 - p2;

}
void test5() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = &a[2];
	int j = p[1];
	cout << j << endl;
	int k = p[-2];
	cout << k << endl;
}
int main() {
	test5();
	return 0;
}
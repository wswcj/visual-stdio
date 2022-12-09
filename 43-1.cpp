#include<iostream>
#include<vector>
using namespace std;
void test1() {

	vector<int> v = { 1, 2, 3, 4, 5 };
	for (int& i : v) {
		i++;
	}
	for (int i : v) {
		cout << i << " ";
	}
}

//插入排序
void insertSort(int* a, int n) {
	for (int i = 0; i < n - 1; ++i) {
		int end = i;
		int tem = a[i + 1];
		while (end >= 0) {
			if (tem < a[end]) {
				a[end + 1] = a[end];
				--end;
			}
			else {
				break;
			}
		}
		a[end + 1] = tem;
	}
}
void test2() {
	int a[] = { 1, 2, 3, 4, 9, 7, 6, 5, 0 };
	insertSort(a, 9);
	for (int i : a) {
		cout << i << " ";
	}
	cout << endl;
}

//希尔排序
void shellSort(int* a, int n) {
	int gap = n;
	while (gap > 1) {
		gap = gap / 2;
		for (int i = 0; i < n - gap; ++i) {
			int end = i;
			int tem = a[end + gap];
			while (end >= 0) {
				if (tem < a[end]) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tem;
		}
	}
}

void test3() {
	int a[] = { 1, 2, 3, 4, 9, 7, 6, 5, 0 };
	shellSort(a, 9);
	for (int i : a) {
		cout << i << " ";
	}
	cout << endl;
}

//选择排序
void selectSort(int* a, int n) {
	int begin = 0, end = n - 1;
	while (begin < end) {
		int maxi = begin;
		int mini = begin;
		for (int i = begin; i <= end; ++i) {
			if (a[i] < a[mini]) {
				mini = i;
			}
			if (a[i] > a[maxi]) {
				maxi = i;
			}
		}
		swap(a[mini], a[begin]);
		if (maxi == begin) {
			maxi = mini;
		}
		swap(a[maxi], a[end]);
		begin++;
		end--;
	}
}
void test4() {
	int a[] = { 1, 2, 3, 4, 9, 7, 6, 5, 0 };
	selectSort(a, 9);
	for (int i : a) {
		cout << i << " ";
	}
	cout << endl;
}

//冒泡排序
void bubbleSort(int* a, int n) {
	int end = n;
	while (end) {
		int flag = 0;
		for (int i = 1; i < end; ++i) {
			if (a[i - 1] > a[i]) {
				swap(a[i - 1], a[i]);
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
		--end;
	}
}
void test5() {
	int a[] = { 1, 2, 3, 4, 9, 7, 6, 5, 0 };
	bubbleSort(a, 9);
	for (int i : a) {
		cout << i << " ";
	}
	cout << endl;
}

//快速排序
void quickSort(int* a, int begin, int end) {
	if (begin >= end) {
		return;
	}
	int left = begin;
	int right = end;
	int key = begin;
	while (begin < end) {
		while (a[end] >= a[key] && begin < end) {
			--end;
		}
		while (a[begin] <= a[key] && begin < end) {
			++begin;
		}
		swap(a[begin], a[end]);
	}
	swap(a[key], a[end]);
	key = end;
	quickSort(a, left, key - 1);
	quickSort(a, key + 1, right);
}
void test6() {
	int a[] = { 1, 2, 3, 4, 9, 7, 6, 5, 0 };
	quickSort(a, 0, 8);
	for (int i : a) {
		cout << i << " ";
	}
	cout << endl;
}
int main() {
	test6();
	return 0;
}
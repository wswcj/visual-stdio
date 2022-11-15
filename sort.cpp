#include<iostream>
using namespace std;
void insertSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {//i < n - 1因为前n位已经有序了,现在要插入第n + 1位且下标从0开始
		int j = i;//记录有序序列的最后一位
		int tmp = a[j + 1];
		while (j >= 0) {
			if (tmp < a[j]) {
				a[j + 1] = a[j];
				j--;
			}
			else {
				break;
			}
		}
		a[j + 1] = tmp;
	}
}
void test1() {
	int a[10] = { 2, 3, 5, 7, 8, 9, 21, 11, 10, 0 };
	insertSort(a, 10);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}
void shellSort(int* a, int n) {
	int gap = n;
	while (n > 1) {//现判断后折半
		gap /= 2;
		for (int i = 0; i < n - gap; i++) {//n - gap  - 1与n - 1交换当gap = 1时与插人排序一样
			int j = i;
			int tmp = a[j + gap];
			while (j >= 0) {
				if (tmp < a[j]) {
					a[j + gap] = a[j];
					j -= gap;
				}
				else {
					break;
				}
			}
			a[j + gap] = tmp;
		}
	}
}
void test2() {
	int a[10] = { 2, 3, 5, 7, 8, 9, 21, 11, 10, 0 };
	shellSort(a, 10);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}
void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
//一次选择出最小和最大两个数分别插入前面和末尾
void selectSort(int* a, int n) {
	int begin = 0, end = n - 1;//保存第一个和最后一个数的下标,且随排序变化
	while (begin < end) {
		int maxi = begin;
		int mini = begin;
		for (int i = begin; i <= end; i++) {
			if (a[i] > a[maxi]) {
				maxi = i;
			}
			if (a[i] < a[mini]) {
				mini = i;
			}
		}
		swap(a[begin], a[mini]);
		if (begin == maxi) {//假如begin是最大值会被mini换走,所以要判断
			maxi = mini;
		}
		swap(a[end], a[maxi]);
		end--;
		begin++;
	}
}
void test3() {
	int a[10] = { 2, 3, 5, 7, 8, 9, 21, 11, 10, 0 };
	selectSort(a, 10);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}
//冒泡排序
void bubbleSort(int* a, int n) {
	for (int i = 0; i < n; i++) {
		int flag = 0;
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}
}
void test4() {
	int a[10] = { 2, 3, 5, 7, 8, 9, 21, 11, 10, 0 };
	bubbleSort(a, 10);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}
void quickSort(int* a, int begin, int end) {
	if (begin >= end) {//容易遗漏
		return;
	}
	int left = begin;
	int right = end;
	int key = begin;
	while (begin < end) {
		while (a[end] >= a[key] && begin < end) {//必须右指针先走
			end--;
		}
		while (a[begin] <= a[key] && begin < end) {
			begin++;
		}
		swap(a[begin], a[end]);
	}
	swap(a[key], a[end]);
	key = end;
	quickSort(a, left, key - 1);//key已经排序好了
	quickSort(a, key + 1, right);
}
void test5() {
	int a[10] = { 1, 5, 3, 5, 7, 8, 9 , 0, 10, 9 };
	quickSort(a, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}
int main() {
	test5();
	return 0;
}
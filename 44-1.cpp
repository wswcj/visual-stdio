#include<iostream>
#include<vector>
using namespace std;

void insertSort(int* a, int n) {
	for (int i = 0; i < n - 1; ++i) {
		int end = i;
		int tem = a[end + 1];
		while (end >= 0) {
			if (a[end] > tem) {
				a[end + 1] = a[end];
				--end;
			}
			else
				break;
		}
		a[end + 1] = tem;
	}
}
void test1() {
	int a[] = { 1, 2, 3, 4, 9, 7, 6, 5, 0 };
	insertSort(a, 9);
	for (int i : a) {
		cout << i << " ";
	}
	cout << endl;

}
void shellSort(int* a, int n) {

	int gap = n;
	while (gap) {
		gap /= 2;
		for (int i = 0; i < n - gap; ++i) {
			int end = i;
			int tem = a[end + gap];
			while (end >= 0) {
				if (a[end] > tem) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tem;
		}
		
	}
}
void test2() {
	int a[] = { 1, 2, 3, 4, 9, 7, 6, 5, 0 };
	shellSort(a, 9);
	for (int i : a) {
		cout << i << " ";
	}
	cout << endl;
}

void selectSort(int* a, int n) {
	int begin = 0;
	int end = n - 1;
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
		swap(a[begin], a[mini]);
		if (mini == begin) {
			maxi = mini;
		}
		swap(a[end], a[maxi]);
		begin++;
		end--;
	}
}
void test3() {
	int a[] = { 1, 2, 3, 4, 9, 7, 6, 5, 0 };
	selectSort(a, 9);
	for (int i : a) {
		cout << i << " ";
	}
	cout << endl;
}
void bubbleSort(int* a, int n) {
	int end = n - 1;
	while (end) {
		int flag = 0;
		for (int i = 0; i < end; ++i) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
		end--;
	}
}
void test4() {
	int a[] = { 1, 2, 3, 4, 9, 7, 6, 5, 0 };
	bubbleSort(a, 9);
	for (int i : a) {
		cout << i << " ";
	}
	cout << endl;
} 
void quickSort(int* a, int begin, int end) {
	if (begin >= end) {
		return;
	}
	int left = begin;
	int right = end;
	int key = begin;
	while (begin < end) {
		while (a[end] > a[key] && begin < end) {
			end--;
		}
		while (a[begin] < a[key] && begin < end) {
			begin++;
		}
		swap(a[begin], a[end]);
	}
	swap(a[key], a[end]);
	key = end;
	quickSort(a, left, key - 1);
	quickSort(a, key + 1, right);
}
void test5() {
	int a[] = { 5, 2, 3, 4, 9, 7, 6, 1, 0 };
	quickSort(a, 0, 8);
	for (int i : a) {
		cout << i << " ";
	}
	cout << endl;
}
int main() {
	test5();
	return 0;
}
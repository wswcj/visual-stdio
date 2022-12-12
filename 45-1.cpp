#include<iostream>
using namespace std;

int maxBit(int* a, int n) {
	int p = 1;
	int d = 10;
	for (int i = 0; i < n; ++i) {
		while (a[i] >= d) {
			d *= 10;
			++p;
		}
	}
	return p;
}

void radixSort(int* a, int n) {
	int d = maxBit(a, n);
	//int d = 2;
	int* tmp = new int[n];
	int count[10];
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; ++i) {
		for (j = 0; j < 10; ++j) {
			count[j] = 0;
		}
		for (j = 0; j < n; ++j) {
			k = a[j] / radix % 10;
			count[k]++;
		}
		for (j = 1; j < 10; ++j) {
			count[j] = count[j - 1] + count[j];
		}
		for (j = n - 1; j >= 0; --j) {
			k = a[j] / radix % 10;
			tmp[count[k] - 1] = a[j];
			count[k]--;
		}
		for (j = 0; j < n; ++j) {
			a[j] = tmp[j];
		}
		radix *= 10;
	}

}
void test1() {

	int a[] = { 1, 2, 3, 4, 9, 7, 6, 5, 0 };
	radixSort(a, 9);
	for (int i : a) {
		cout << i << " ";
	}
	cout << endl;
}
int a[20] = { 1, 2, 3, 4, 7, 5, 6, 9, 0, 8};
int b[20];
void merge(int low, int mid, int high) {
	int i = low, j = mid + 1, k = low;
	while (i <= mid && j <= high) {
		if (a[i] < a[j]) {
			b[k++] = a[i++];
		}
		else {
			b[k++] = a[j++];
		}
	}
	while (i <= mid) {
		b[k++] = a[i++];
	}
	while (j <= high) {
		b[k++] = a[j++];
	}
	for (int i = low; i <= high; ++i) {
		a[i] = b[i];
	}
}

void mergSort(int x, int y) {
	if (x >= y) {
		return;
	}
	int mid = (x + y) / 2;
	mergSort(x, mid);
	mergSort(mid + 1, y);
	merge(x, mid, y);
}
void test2() {
	mergSort(0, 9);
	for (int i = 0; i < 10; ++i) {
		cout << a[i] << " ";
	}
	
}
void quickSort(int* a, int begin, int end) {
	if (begin >= end)
		return;
	int left = begin, right = end;
	int key = begin;
	while (begin < end) {
		while (a[key] < a[end] && begin < end)
			end--;
		while (a[key] > a[begin] && begin < end)
			begin++;
		swap(a[begin], a[end]);
	}
	swap(a[key], a[end]);
	key = end;
	quickSort(a, left, key - 1);
	quickSort(a, key + 1, right);
}

void test3() {
	int a[] = { 5, 2, 3, 4, 9, 7, 6, 1, 0 };
	quickSort(a, 0, 8);
	for (int i : a) {
		cout << i << " ";
	}
	cout << endl;
}


int main() {
	test3();
	return 0;
}
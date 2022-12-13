#include<iostream>
using namespace std;

void quickSort(int* a, int begin, int end) {

	if (begin >= end) {
		return;
	}
	int left = begin, right = end;
	int key = begin;
	while (begin < end) {
		while (a[end] > a[key] && begin < end)
			end--;
		while (a[begin] < a[key] && begin < end)
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
int maxBit(int* a, int n) {
	int d = 1;
	int p = 10;
	for (int i = 0; i < n; ++i) {
		while (a[i] >= p) {
			p *= 10;
			++d;
		}
	}
	return d;
}

void radixSort(int* a, int n) {
	int count[10];
	int* tmp = new int[n];
	int d = maxBit(a, n);
	int radix = 1;
	for (int i = 1; i <= d; ++i) {
		for (int j = 0; j < 10; ++j) {
			count[j] = 0;
		}
		for (int j = 0; j < n; ++j) {
			int k = a[j] / radix % 10;
			count[k]++;
		}
		for (int j = 1; j < 10; ++j) {
			count[j] = count[j] + count[j - 1];
		}
		for (int j = n - 1; j >= 0; --j) {
			int k = a[j] / radix % 10;
			tmp[count[k] - 1] = a[j];
			count[k]--;
		}
		for (int j = 0; j < n; ++j) {
			a[j] = tmp[j];
		}
		radix *= 10;
	}
}
int a[20] = { 5, 21, 301, 4, 9, 7, 6, 1, 0 , 8};
int b[20];
void merge(int left, int mid, int right) {
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right) {
		if (a[i] < a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while (i <= mid)
		b[k++] = a[i++];
	while (j <= right)
		b[k++] = a[j++];
	for (int m = left; m <= right; ++m)
		a[m] = b[m];
}
void mergeSort(int x, int y) {
	if (x >= y)
		return;
	int mid = (x + y) / 2;
	mergeSort(x, mid);
	mergeSort(mid + 1, y);
	merge(x, mid, y);
}

void test1() {
	mergeSort(0, 9);
	for (int i = 0; i < 10; ++i) {
		cout << a[i] << " ";
	}
}
void test2() {
	int a[] = { 5, 21, 301, 4, 9, 7, 6, 1, 0 };
	radixSort(a, 9);
	for (int i : a) {
		cout << i << " ";
	}
	cout << endl;
}
void down(int* a, int i, int n) {
	int parent = i;
	int child = 2 * i + 1;
	while (child < n) {
		if (child < n - 1 && a[child] < a[child + 1]) {
			child++;
		}
		if (a[child] > a[parent]) {
			swap(a[child], a[parent]);
			parent = child;
		}
		child = child * 2 + 1;
	}
}

void buildHeap(int* a, int n) {
	for (int i = n / 2 - 1; i >= 0; --i) {
		down(a, i, n);
	}
}

void heapSort(int* a, int n) {
	buildHeap(a, n);
	for (int i = n - 1; i > 0; --i) {
		swap(a[i], a[0]);
		down(a, 0, i);
	}
}
void test4() {
	int a[] = { 5, 21, 301, 4, 9, 7, 6, 1, 0 };
	heapSort(a, 9);
	for (int i : a) {
		cout << i << " ";
	}
	cout << endl;
}
int main() {
	test4();
	return 0;
}
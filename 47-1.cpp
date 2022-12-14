#include<iostream>
using namespace std;
//从小到大排序
void down(int* a, int i, int n)  {
	int parent = i;
	int son = 2 * i + 1;
	while (son < n) {
		if (a[son + 1] > a[son] && son < n - 1) {
			son++;
		}
		if (a[son] > a[parent]) {
			swap(a[son], a[parent]);
			parent = son;
		}
		else {
			break;
		}
		son = son * 2 + 1;
	}
}

//从大到小排序
//void down(int* a, int i, int n) {
//
//	int child = 2 * i + 1;
//	int key = a[i];
//	while (child < n) {
//		if (child < n - 1 && a[child] > a[child + 1]) {
//			child++;
//		}
//		if (key > a[child]) {
//			swap(a[i], a[child]);
//			i = child;
//		}
//		else {
//			break;
//		}
//		child = child * 2 + 1;
//	}
//}
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

void test1() {
	int a[] = { 5, 21, 301, 4, 9, 7, 6, 1, 0 };
	heapSort(a, 9);
	for (int i : a) {
		cout << i << " ";
	}
	cout << endl;
}
int main() {
	test1();
	return 0;
}
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int n, a[12000], b[12000];//a数组用来输入数据和储存排序后的数据,b数组用来辅助排序
void merge(int low, int mid, int high) {//low-mid是第一个数列,mid+1-high是第二个数列
	int i = low, j = mid + 1, k = low;//k用来将a数组中小的元素放入b数组中
	while (i <= mid && j <= high) {//寻找两个数列中小的元素放人b数组中
		if (a[i] < a[j]) {
			b[k++] = a[i++];
		}
		else {
			b[k++] = a[j++];
		}
	}
	while (i <= mid) {//当一个数列放完了
		b[k++] = a[i++];
	}
	while (j <= high) {
		b[k++] = a[j++];
	}
	for (i = low; i <= high; i++) {//把b数组中的元素放回a数组中
		a[i] = b[i];
	}
}
void mergeSort(int x, int y) {
	if (x >= y) {
		return;
	}
	int mid = (x + y) / 2;
	mergeSort(x, mid);
	mergeSort(mid + 1, y);
	merge(x, mid, y);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)//从下标1开始储存
		cin >> a[i];//为什么输入数据才能排序,用列表初始话的不能排序(可以不把a数组设置成全局变量)
	mergeSort(1, n);  //调用函数
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	return 0;
}
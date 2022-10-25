#include<iostream>
using namespace std;
int IsPrime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)//<=的原因是当n的平方根为整数时就不是质数
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
void test1()
{
	int count = 0;
	for (int i = 101; i <= 200; i++)
	{
		if (IsPrime(i) == 1)
		{
			cout << i << " ";
			count++;
		}
	}
	cout << endl;
	cout << count << endl;
}
void print(int num)
{
	if (num > 9)
	{
		print(num / 10);
	}
	cout << num % 10 << "  ";
}
void  test2()
{
	int num = 0;
	cin >> num;
	print(num);

}
int StrLength(char* str)
{
	if (*str != '\0')
	{
		return 1 + StrLength(str + 1);
	}
	else
		return 0;
}
void test3()
{
	char arr[] = "bit";
	int len = StrLength(arr);
	cout << len << endl;
}
int MyBinarySearch(int arr[], int len, int n)
{
	int left = 0;
	int right = len - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > n)
		{
			right = mid - 1;
		}
		else if (arr[mid] < n)
		{
			left = mid+1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
void test4()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int ret = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int n = 0;
	cin >> n;
	ret = MyBinarySearch(arr, sz, n);
	if (ret != -1)
		cout << "找到了,下标为:" << ret << endl;
	else
		cout << "没找到" << endl;
}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}

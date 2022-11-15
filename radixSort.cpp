/**
* name:基数排序
* time:15/8/16 15:00
* environment: ubuntu 14.04， sublime text 3
*/
#include <iostream>
using namespace std;

/*
* 打印数组
*/
void printArray(int array[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
/*
*求数据的最大位数,决定排序次数
*/
int maxbit(int data[], int n)
{
    int d = 1; //保存最大的位数
    int p = 10;
    for (int i = 0; i < n; ++i)
    {
        while (data[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}
void radixsort(int data[], int n) //基数排序
{
    int d = maxbit(data, n);
    int* tmp = new int[n];
    int count[10]; //计数器
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++) //进行d次排序
    {
        for (j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for (j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for (j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //count数组后一位等于前两项和有妙用,自己结合下面的for循环推一下就知道了
        for (j = n - 1; j >= 0; j--) //为啥要逆序呢?
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for (j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
}

int main()
{
    int array[10] = { 73,22,93,43,55,14,28,65,39,81 };
    radixsort(array, 10);
    printArray(array, 10);
    return 0;
}

//结果
//14 22 28 39 43 55 65 73 81 93  
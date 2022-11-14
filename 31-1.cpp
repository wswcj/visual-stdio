#include<iostream>
#include<vector>
using namespace std;
void test1() {
	vector<int> v;
	v.push_back(10);
	cout << v.size() << endl;
	const int n = v.size();
	int** dp = new int* [n];
	for (int i = 0; i < n; i++) {
		dp[i] = new int[2];
	}
} 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int n = prices.size();
        int** dp = new int* [n];
        for (int i = 0; i < n; i++) {
            dp[i] = new int[2];
        }
        dp[0][1] = -prices[0];
        dp[0][0] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};
void test2() {
    int var = 1;
    //var + 10 = 1;err 表达式必须是左值;
    int* p = &var;
    decltype(*p) a = var;//*p是左值所以a的类型是int&
    decltype(&p) b = &p;//&p是右值,b的类型是int**
}
void test3() {
    vector<int> v(5, 1);
    int n = v.size();
    n = -1;
    cout << n << endl;
}
//顺序查找
int searchSeq(vector<int> v, int n) {
    int s = v.size();
    for (int i = s - 1; i > 0; i--) {
        if (v[i] == n) {
            return i;
        }
    }
    return 0;
}
//带哨兵的顺序查找
int search_Seq(vector<int> v, int n) {
    int s = v.size();
    v[0] = n;
    int i = 0;
    for ( i = s - 1; i >= 0 && v[i] != n; i--);
    return i;
}
//折半查找
int searchSeq1(vector<int> v, int n) {
    int s = v.size();
    int l = 1, h = s - 1;
    while (l <= h) {
        int mid = (l + h) >> 1;
        if (v[mid] < n) {
            l = mid + 1;
        }
        else if (v[mid] > n) {
            h = mid - 1;
        }
        else {
            return mid;
        }
    }
    return 0;
}
//折半查找-递归
int searchSeq2(vector<int> v, int n, int l, int h) {
    if (l > h) {
        return 0;
    }
    int mid = l + (h - l) / 2;
    if (v[mid] == n) {
        return mid;
    }
    else if (v[mid] > n) {
        return searchSeq2(v, n, l, mid - 1);
    }
    else {
        return searchSeq2(v, n, mid + 1, h);
    }
}
void test4() {
    vector<int> v1 = { 0, 5, 7, 19, 21, 13, 56, 64, 92, 88, 80, 75 };
    int ret2 = searchSeq2(v1, 21, 1, 11);
    cout << ret2 << endl;
    int ret = searchSeq(v1, 21);
    cout << ret << endl;
    int ret1 = search_Seq(v1, 21);
    cout << ret1 << endl;
    int ret3 = searchSeq1(v1, 21);
    cout << ret3 << endl;
}
//分块查找
typedef struct {
    int key[10];
    int len;
}Table;
Table table;
int blockSearch(vector<int> v, int n) {
    int low = 1, high = table.len, mid;
    while (low <= high) {
        mid = (low + high) >> 1;
        if (n <= table.key[mid]) {
            if (n <= table.key[mid - 1]) {
                high = mid - 1;
            }
            
        }
        else {
            low = mid + 1;
        }
    }
    return 0;
}
void test5() {
    vector<int> v = { 0,22,12,3,8,9,20,33,43,44,38,24,48,60,58,74,57,86,53 };
}
//二叉排序树的递归排序
typedef struct BSTNode {
    int data;
    struct BSTNode* lchild, * rchild;
}BSTNode, * BSTree;
void createTree(BSTree T, int n) {
    T->lchild = nullptr;
    T->rchild = nullptr;
    cout << "输入第一个数: ";
    cin >> T->data;
    for (int i = 1; i < n; i++) {
        BSTNode* s = new BSTNode;
        cout << "输入第" << i + 1 << "个数: ";
        cin >> s->data;
        s->lchild = nullptr;
        s->rchild = nullptr;
        BSTNode* p = T;
        while (p != nullptr) {
            if (s->data < p->data) {
                if (p->lchild == nullptr) {
                    p->lchild = s;
                    break;
                }
                else {
                    p = p->lchild;
                }
            }
            else {
                if (p->rchild == nullptr) {
                    p->rchild = s;
                    break;
                }
                else {
                    p = p->rchild;
                }
            }
        }
    }
}
BSTree searchBST(BSTree T, int n) {
    if (!T || n == T->data) {
        return T;
    }
    else if (n < T->data) {
        return searchBST(T->lchild, n);
    }
    else {
        return searchBST(T->rchild, n);
    }
}
void test6() {
    BSTree T = new BSTNode;
    createTree(T, 9);
    BSTNode* pos = searchBST(T, 111);
    if (pos != nullptr) {
        cout << pos->data;
    }
    else {
        cout << "没找到!" << endl;
    }
}
int main() {
    test6();
	return 0;
}
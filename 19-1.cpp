#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {};
};
void test1()
{
	ListNode* head = new ListNode(5);
	cout << head->val << endl;
}
void test2()
{
	int count = 2;
	while (count--) {
		cout << "hh" << endl;
	}
	cout << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "hh" << endl;
	}
}
int main()
{
	//test1();
	test2();
	return 0;
}
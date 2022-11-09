#include<iostream>
using namespace std;
typedef struct Lnode{
	int elem;
	struct Lnode* next;
}Lnode, * LinkList;
void initList(LinkList& L) {
	L = new Lnode;
	L->next = L;
}
void createList(LinkList& L, int n) {//尾插法而且带尾指针
	Lnode* p, * q;
	q = L;
	for (int i = 0; i < n; i++) {
		cin >> p->elem;
		p->next = nullptr;
		q->next = p;
		q = p;
		L = p;//尾指针指向最后一个结点
	}
}
LinkList connectList(const LinkList& L1, const LinkList& L2) {
	Lnode* p = L1->next;
	L1->next = L2->next->next;
	delete L2->next;
	L2->next = p;
	return L2;//注意返回的是L2的尾指针
}
int main() {

	return 0;
}
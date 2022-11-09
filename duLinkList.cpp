#include<iostream> 
using namespace std;
typedef struct Lnode {
	int elem;
	struct Lnode* next, * prior;
}duLnode, * duLinkList;
void initList(duLinkList& L) {
	L = new duLnode;
	L->next = L;
	L->prior = nullptr;
}
void createList(duLinkList& L, int n) {
	duLnode* p, * q;
	q = L;
	for (int i = 0; i < n; i++) {
		p = new duLnode;
		cin >> p->elem;
		p->next = q->next;
		q->next = p;
		q = p;
	}
}
void insertList(duLinkList& L, int i) {
	duLnode* p = L->next;
	int j = 1;
	while (!p && j < i) {
		p = p->next;
	}
	if (!p || j > i) {
		cout << "插入位置非法!!!" << endl;
		return;
	}
	duLnode* s = new duLnode;
	cin >> s->elem;
	p->prior->next = s;
	s->prior = p->next;
	s->next = p;
	p->prior = s;
}
void deleteList(duLinkList& L, int n) {
	duLnode* p = L->next;
	int j = 1;
	while (p && j < n) {
		p = p->next;
	}
	if (!p && j > n) {
		cout << "删除位置非法!!!" << endl;
		return;
	}
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
}
int main() {

	return 0;
}
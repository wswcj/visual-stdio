#include<iostream>
#include<string>
using namespace std;
#define MAXSIZE 50
typedef struct Pnode {
	float coef;
	int expn;
	struct Pnode* next;
}Pnode, * Polynomial;
void initPolyn(Polynomial& P) {
	P = new Pnode;
	P->next = nullptr;
}
void createPolyn(Polynomial& P, int n) {//创建有序的链表
	cout << "请输入表达式的系数和指数!" << endl;
	for (int i = 1; i <= n; i++) {
		Pnode* s = new Pnode;
		cout << "请输入系数: " << endl;
		cin >> s->coef;
		cout << "请输入指数: " << endl;
		cin >> s->expn;
		Pnode* pre = P;
		Pnode* q = P->next;
		while (q && q->expn < s->expn) {
			pre = q;
			q = q->next;
		}
		pre->next = s;
		s->next = q;
	}
}
void connectPolyn(Polynomial P1, Polynomial P2, Polynomial& P3) {
	Pnode* p1 = P1->next, * p2 = P2->next, *p3 = P3 = P1; 
	while (p1 && p2) {
		if (p1->expn == p2->expn) {
			if ((p1->coef + p2->coef) == 0) {
				p1 = p1->next;
				p2 = p2->next;
				p3->next = nullptr;
			}
			else {
				p3->next = p1;
				p1->coef += p2->coef;
				p1 = p1->next;
				p2 = p2->next;
			}
		}
		else if (p1->expn < p2->expn) {
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
		}
		else {
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
	}
	p3->next = p1 ? p1 : p2;
}
void showPolyn(const Polynomial& P) {
	Pnode* p = P->next;
	while (p) {
		cout << p->coef << "," << p->expn << "  ";
		p = p->next;
	}
	cout << endl;
}
void test1() {
	Pnode* P1, * P2, * P3;
	initPolyn(P1);
	initPolyn(P2);
	createPolyn(P1, 2);
	createPolyn(P2, 3);
	cout << "P1表达式为: " << endl;
	showPolyn(P1);
	cout << "P2表达式为: " << endl;
	showPolyn(P2);
	connectPolyn(P1, P2, P3);//合并以后P1和P2都被修改了
	/*cout << "P1表达式为: " << endl;
	showPolyn(P1);
	cout << "P2表达式为: " << endl;
	showPolyn(P2);*/
	cout << "P3表达式为: " << endl;
	showPolyn(P3);
}
void test2() {
	string str1 = "helloworld";
	//str1.append("helloworld", 5, 2);
	//cout << str1 << endl;
	str1.replace(1, 3, "1111");
	cout << str1 << endl;
}
void fun(int a[]) {
	a[1] = 1;
}
void test3() {
	int a[10] = { 0 };
	fun(a);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}

int main() {
	test3();
	return 0;
}
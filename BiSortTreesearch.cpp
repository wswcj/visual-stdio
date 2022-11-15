#include<iostream>
using namespace std;
//二叉排序树的递归排序
typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}Node, * Tree;
void createTree(Tree& tree, int val) {
	Node* node = new Node;
	node->data = val;
	node->left = nullptr;
	node->right = nullptr;
	if (tree == nullptr) {
		tree = node;
	}
	else {
		Node* temp = tree;
		while (temp != nullptr) {
			if (val < temp->data) {
				if (temp->left == nullptr) {
					temp->left = node;
					return;
				}
				else {
					temp = temp->left;
				}
			}
			else {
				if (temp->right == nullptr) {
					temp->right = node;
					return;
				}
				else {
					temp = temp->right;
				}
			}
		}
	}
}
void preOrder(Tree tree) {
	if (tree == nullptr) {
		return;
	}
	preOrder(tree->left);
	cout << tree->data << " ";
	preOrder(tree->right);
}
Tree searchBST(Tree tree, int val) {
	if (!tree || val == tree->data) {
		return tree;
	}
	else if (val > tree->data) {
		return searchBST(tree->right, val);
	}
	else {
		return searchBST(tree->left, val);
	}
}
void test1() {
	int a[7] = { 7 ,4 ,5, 6, 1, 8, 9 };
	Tree tree;
	tree = nullptr;//遗漏会出bug
	int i;
	int len = 7;
	for (i = 0; i < len; i++) {
		createTree(tree, a[i]);
	}
	preOrder(tree);
	cout << endl;
	Node* p = searchBST(tree, 6);
	if (p) {
		cout << "找到了: " << p->data << endl;
	}
}
int main() {
	test1();
	return 0;
}
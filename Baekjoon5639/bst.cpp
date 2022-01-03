#include <iostream>

using namespace std;
typedef struct Node {
	int data;
	struct Node* L;
	struct Node* R;
}Node;

Node* insert(Node* tree, int item) {
	Node* temp, * parent;
	Node* newnode = new Node();
	newnode->L = newnode->R = NULL;
	newnode->data = item;
	temp = tree;
	parent = NULL;
	while (temp != NULL) {
		if (item == temp->data)return 0;
		parent = temp;
		if (item < temp->data)
			temp = temp->L;
		else
			temp = temp->R;
	}
	if (parent != NULL)
		if (item < parent->data)
			parent->L = newnode;
		else
			parent->R = newnode;
	else
		tree = newnode;

	return tree;
}
void disp(Node* tree) {
	if (tree) {
		disp(tree->L);
		disp(tree->R);
		printf("%d\n", tree->data);
	}
}
int main() {
	Node* bst = NULL;
	int val;
	while (cin >> val) {
		if (val == EOF) break;
		bst = insert(bst, val);
	}
	disp(bst);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
	char data;
	struct Node* L;
	struct Node* R;
}Node;

//////////전위순회////////////
void disp(Node* tree) {
	if (tree) {
		printf("%c", tree->data);
		disp(tree->L);
		disp(tree->R);
	}
}
//////////중위순회////////////
void disp1(Node* tree) {
	if (tree) {
		disp1(tree->L);
		printf("%c", tree->data);
		disp1(tree->R);
	}
}
//////////후위순회////////////
void disp2(Node* tree) {
	if (tree) {
		disp2(tree->L);
		disp2(tree->R);
		printf("%c", tree->data);
	}
}
Node* makenode(char data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->L = NULL;
	newnode->R = NULL;
	newnode->data = data;
	return newnode;
}
Node* Search(Node** tmp, char t, char l, char r)
{
	if (*tmp == NULL)
		return *tmp;
	if ((*tmp)->data == t)
	{
		if (l != '.') (*tmp)->L = makenode(l);
		else (*tmp)->L = NULL;
		if (r != '.') (*tmp)->R = makenode(r);
		else (*tmp)->R = NULL;
		return *tmp;
	}
	else
	{
		Search(&(*tmp)->L, t, l, r);
		Search(&(*tmp)->R, t, l, r);
		return *tmp;
	}
}
Node* Insert(Node* tmp, char t, char l, char r)
{
	if (tmp == NULL)
	{
		tmp = makenode(t);
		tmp->data = t;
		if (l != '.')
		{
			tmp->L = makenode(l);
		}
		if (r != '.')
		{
			tmp->R = makenode(r);
		}
		return tmp;
	}
	else
	{
		Search(&tmp, t, l, r);
		return tmp;
	}
}
int main(void) {
	Node* tree = NULL;
	int n;
	scanf("%d", &n);
	char parent, left, right;
	for (int i = 0; i < n; i++) {
		scanf(" %c %c %c", &parent, &left, &right);
		tree = Insert(tree, parent, left, right);
	}
	disp(tree);
	printf("\n");
	disp1(tree);
	printf("\n");
	disp2(tree);
	return 0;
}
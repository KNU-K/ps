#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct NODE {
	char data;
	struct NODE* left;
	struct NODE* right;
}node;

node nodes[27];
void preOrder(node* curNode) {
	printf("%c", curNode->data);
	if (curNode->left != NULL)
		preOrder(curNode->left);
	if (curNode->right != NULL)
		preOrder(curNode->right);
}

void inOrder(node* curNode) {
	if (curNode->left != NULL)
		inOrder(curNode->left);
	printf("%c", curNode->data);
	if (curNode->right != NULL)
		inOrder(curNode->right);
}
void postOrder(node* curNode) {
	if (curNode->left != NULL)
		postOrder(curNode->left);
	if (curNode->right != NULL)
		postOrder(curNode->right);
	printf("%c", curNode->data);
}
int main() {
	int n;
	fflush(stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char mainNode,leftNode, rightNode;
		fflush(stdin);
		scanf(" %c %c %c", &mainNode, &leftNode, &rightNode);
		nodes[mainNode - 'A'].data = mainNode;
		if (leftNode == '.')
			nodes[mainNode - 'A'].left = NULL;
		else
			nodes[mainNode - 'A'].left = &(nodes[leftNode - 'A']);
		if(rightNode == '.')
			nodes[mainNode - 'A'].right = NULL;
		else
			nodes[mainNode - 'A'].right = &(nodes[rightNode - 'A']);
	}
	preOrder(&(nodes[0]));
	printf("\n");
	inOrder(&(nodes[0]));
	printf("\n");
	postOrder(&(nodes[0]));
}

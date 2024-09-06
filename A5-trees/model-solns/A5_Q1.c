#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right, *inOrderSuccessor;
};

struct node *createNode(int item) {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = temp->inOrderSuccessor = NULL;
	return temp;
}

struct node *getSampleTree() {
	struct node *root = createNode(5);
	root->left = createNode(9);
	root->right = createNode(7);
	root->left->left = createNode(3);
	root->right->left = createNode(4);
	root->right->right = createNode(1);
	root->right->right->left = createNode(6);
	root->right->right->right = createNode(2);
	return root;
}

struct node *assignInOrderSuccessor(struct node *curr, struct node *last) {
	if (curr != NULL) {
		last = assignInOrderSuccessor(curr->left, last);
		if (last != NULL) last->inOrderSuccessor = curr;
		last = assignInOrderSuccessor(curr->right, curr);
	}
	return last;
}

struct node *getLeftmostNode(struct node *curr) {
	if (curr->left != NULL) getLeftmostNode(curr->left);
	else return curr;
}

void printInOrderSuccessor(struct node *curr) {
  if (curr->inOrderSuccessor != NULL) {
    printf("The inorder successor of %d is %d\n", curr->key, curr->inOrderSuccessor->key);
    printInOrderSuccessor(curr->inOrderSuccessor);
  }
}

int main() {
	struct node *root = getSampleTree();
	assignInOrderSuccessor(root, NULL);
	printInOrderSuccessor(getLeftmostNode(root));
	return 0;
}


#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right;
	
	int hop[10];
};

struct node *createNode(int item) {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	
	int i;
	for (i = 0; i < 10; i++) temp->hop[i] = 0;
	return temp;
}

struct node *getSampleTree() {
	struct node *root = createNode(10);
	root->left = createNode(7);
	root->right = createNode(2);
	root->left->left = createNode(11);
	root->right->left = createNode(5);
	root->right->right = createNode(16);
	root->left->left->right = createNode(17);
	root->right->right->left = createNode(9);
	root->right->right->right = createNode(21);
	return root;
}

int isLeaf(struct node *curr) {
	return (curr!=NULL && curr->left==NULL && curr->right==NULL);
}

void detectKHops(struct node *curr, int k) {
	if (curr != NULL) {
		int i;
		
		if (curr->left != NULL) {
			detectKHops(curr->left, k);
			if (isLeaf(curr->left)) curr->hop[0] = 1;
			for (i = 0; i < k; i++) {
				if (curr->left->hop[i]) curr->hop[i+1] = 1;
			}
		}
		
		if (curr->right != NULL) {
			detectKHops(curr->right, k);
			if (isLeaf(curr->right)) curr->hop[0] = 1;
			for (i = 0; i < k; i++) {
				if (curr->right->hop[i]) curr->hop[i+1] = 1;
			}
		}
	}
}

void printKHops(struct node *curr, int k) {
	if (curr != NULL) {
		if (curr->hop[k]) printf("%d ", curr->key);
		printKHops(curr->left, k);
		printKHops(curr->right, k);
	}
}

int main() {
	struct node *root = getSampleTree();
	int hopLimit = 2;
	
	detectKHops(root, hopLimit);
	
	int i;
	for (i = 0; i <= hopLimit; i++) {
		printf("%d-hop away nodes from the leaf nodes: ", i);
		printKHops(root, i);
		printf("\n");
	}
	return 0;
}


// C program for recursive level order traversal in spiral form
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node {
	int data;
	struct node* left;
	struct node* right;
};

/* Function protoypes */
void printGivenLevel(struct node* root, int level, int ltr);
int height(struct node* node);
struct node* newNode(int data);

/* Function to print spiral traversal of a tree*/
void printSpiral(struct node* root)
{
	int h = height(root);
	int i;

	/*ltr -> Left to Right. If this variable is set true,
	then the given level is traversed from left to right. */
	bool ltr = false;
	for (i = 1; i <= h; i++)
    {
		printGivenLevel(root, i, ltr);

		/*Revert ltr to traverse next level in opposite order*/
		ltr = !ltr;
	}
}

/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level, int ltr)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->data);
	else if (level > 1) {
		if (ltr) {
			printGivenLevel(root->left, level - 1, ltr);
			printGivenLevel(root->right, level - 1, ltr);
		}
		else {
			printGivenLevel(root->right, level - 1, ltr);
			printGivenLevel(root->left, level - 1, ltr);
		}
	}
}

/* Compute the "height" of a tree -- the number of
	nodes along the longest path from the root node
	down to the farthest leaf node.*/
int height(struct node* node)
{
	if (node == NULL)
		return 0;
	else {
		/* compute the height of each subtree */
		int lheight = height(node->left);
		int rheight = height(node->right);

		/* use the larger one */
		if (lheight > rheight)
			return (lheight + 1);
		else
			return (rheight + 1);
	}
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
{
	struct node* node = (struct node*) malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/* Driver program to test above functions*/
int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(6);
	root->right->left = newNode(5);
	root->right->right = newNode(4);
	printf("Spiral Order traversal of binary tree is \n");
	printSpiral(root);

	return 0;
}

/*
// C++ implementation of a O(n) time method for spiral order traversal
#include <iostream>
#include <stack>
using namespace std;

// Binary Tree node
struct node {
	int data;
	struct node *left, *right;
};

void printSpiral(struct node* root)
{
	if (root == NULL)
		return; // NULL check

	// Create two stacks to store alternate levels
	stack<struct node*> s1; // For levels to be printed from right to left
	stack<struct node*> s2; // For levels to be printed from left to right

	// Push first level to first stack 's1'
	s1.push(root);

	// Keep printing while any of the stacks has some nodes
	while (!s1.empty() || !s2.empty()) {
		// Print nodes of current level from s1 and push nodes of
		// next level to s2
		while (!s1.empty()) {
			struct node* temp = s1.top();
			s1.pop();
			cout << temp->data << " ";

			// Note that is right is pushed before left
			if (temp->right)
				s2.push(temp->right);
			if (temp->left)
				s2.push(temp->left);
		}

		// Print nodes of current level from s2 and push nodes of
		// next level to s1
		while (!s2.empty()) {
			struct node* temp = s2.top();
			s2.pop();
			cout << temp->data << " ";

			// Note that is left is pushed before right
			if (temp->left)
				s1.push(temp->left);
			if (temp->right)
				s1.push(temp->right);
		}
	}
}

// A utility function to create a new node
struct node* newNode(int data)
{
	struct node* node = new struct node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(6);
	root->right->left = newNode(5);
	root->right->right = newNode(4);
	cout << "Spiral Order traversal of binary tree is \n";
	printSpiral(root);

	return 0;
}

*/

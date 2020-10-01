/* C++ Program to find distance between n1 and n2
using one traversal */
#include <iostream>
using namespace std;

// A Binary Tree Node
struct Node
{
	struct Node *left, *right;
	int key;
};

// Utility function to create a new tree Node
Node* newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}
Node* LCA(Node * root, int n1,int n2)
{
	// Your code here
	if (root == NULL)
	return root;
	if (root->key == n1 || root->key == n2)
	return root;

	Node* left = LCA(root->left, n1, n2);
	Node* right = LCA(root->right, n1, n2);

	if (left != NULL && right != NULL)
		return root;
	if (left != NULL)
		return LCA(root->left, n1, n2);

	return LCA(root->right, n1, n2);
}

// Returns level of key k if it is present in
// tree, otherwise returns -1
int findLevel(Node *root, int k, int level)
{
	if(root == NULL) return -1;
	if(root->key == k) return level;

	int left = findLevel(root->left, k, level+1);
	if (left == -1)
	return findLevel(root->right, k, level+1);
	return left;
}

int findDistance(Node* root, int a, int b)
{
	// Your code here
	Node* lca = LCA(root, a , b);

	int d1 = findLevel(lca, a, 0);
	int d2 = findLevel(lca, b, 0);

	return d1 + d2;
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree given in
	// the above example
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
	cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
	cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
	cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
	cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
	return 0;
}

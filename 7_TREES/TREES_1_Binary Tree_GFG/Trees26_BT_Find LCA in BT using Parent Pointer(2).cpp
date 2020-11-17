// C++ program to find lowest common ancestor using parent pointer
#include <bits/stdc++.h>
using namespace std;

// A Tree Node
struct Node
{
	Node *left, *right, *parent;
	int key;
};

// A utility function to create a new BST node
Node *newNode(int item)
{
	Node *temp = new Node;
	temp->key = item;
	temp->parent = temp->left = temp->right = NULL;
	return temp;
}

/* A utility function to insert a new node with
given key in Binary Search Tree */
Node *insert(Node *node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
	{
		node->left = insert(node->left, key);
		node->left->parent = node;
	}
	else if (key > node->key)
	{
		node->right = insert(node->right, key);
		node->right->parent = node;
	}

	/* return the (unchanged) node pointer */
	return node;
}

// To find LCA of nodes n1 and n2 in Binary Tree
Node *LCA(Node *n1, Node *n2)
{
// Creata a map to store ancestors of n1
map <Node *, bool> ancestors;

// Insert n1 and all its ancestors in map
while (n1 != NULL)
{
	ancestors[n1] = true;
	n1 = n1->parent;
}

// Check if n2 or any of its ancestors is in
// map.
while (n2 != NULL)
{
	if (ancestors.find(n2) != ancestors.end())
		return n2;
	n2 = n2->parent;
}

return NULL;
}

// Driver method to test above functions
int main(void)
{
	Node * root = NULL;

	root = insert(root, 20);
	root = insert(root, 8);
	root = insert(root, 22);
	root = insert(root, 4);
	root = insert(root, 12);
	root = insert(root, 10);
	root = insert(root, 14);

	Node *n1 = root->left->right->left;
	Node *n2 = root->left;
	Node *lca = LCA(n1, n2);

	printf("LCA of %d and %d is %d \n", n1->key, n2->key, lca->key);

	return 0;
}

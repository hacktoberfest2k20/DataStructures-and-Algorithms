// C++ implementation to replace each node
// in binary tree with the sum of its inorder predecessor and successor
#include <bits/stdc++.h>

using namespace std;

// node of a binary tree
struct Node {
	int data;
	struct Node* left, *right;
};

// function to get a new node of a binary tree
struct Node* getNode(int data)
{
	// allocate node
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	// put in the data;
	new_node->data = data;
	new_node->left = new_node->right = NULL;

	return new_node;
}

// function to store the inorder traversal
// of the binary tree in 'arr'
void storeInorderTraversal(struct Node* root,
								vector<int>& arr)
{
	// if root is NULL
	if (!root)
		return;

	// first recur on left child
	storeInorderTraversal(root->left, arr);

	// then store the root's data in 'arr'
	arr.push_back(root->data);

	// now recur on right child
	storeInorderTraversal(root->right, arr);
}

// function to replace each node with the sum of its
// inorder predecessor and successor
void replaceNodeWithSum(struct Node* root,
						vector<int> arr, int* i)
{
	// if root is NULL
	if (!root)
		return;

	// first recur on left child
	replaceNodeWithSum(root->left, arr, i);

	// replace node's data with the sum of its
	// inorder predecessor and successor
	root->data = arr[*i - 1] + arr[*i + 1];

	// move 'i' to point to the next 'arr' element
	++*i;

	// now recur on right child
	replaceNodeWithSum(root->right, arr, i);
}

// Utility function to replace each node in binary tree with the sum of its inorder predecessor and successor

void replaceNodeWithSumUtil(struct Node* root)
{
	// if tree is empty
	if (!root)
		return;

	vector<int> arr;

	// store the value of inorder predecessor
	// for the leftmost leaf
	arr.push_back(0);

	// store the inorder traversal of the tree in 'arr'
	storeInorderTraversal(root, arr);

	// store the value of inorder successor
	// for the rightmost leaf
	arr.push_back(0);

	// replace each node with the required sum
	int i = 1;
	replaceNodeWithSum(root, arr, &i);
}

// function to print the preorder traversal
// of a binary tree
void preorderTraversal(struct Node* root)
{
	// if root is NULL
	if (!root)
		return;

	// first print the data of node
	cout << root->data << " ";

	// then recur on left subtree
	preorderTraversal(root->left);

	// now recur on right subtree
	preorderTraversal(root->right);
}

// Driver program to test above
int main()
{
	// binary tree formation
	struct Node* root = getNode(1); /*		 1	        */
	root->left = getNode(2);	      /*	/ \	        */
	root->right = getNode(3);	 /*    	   2   3	    */
	root->left->left = getNode(4); /*     / \ / \       */
	root->left->right = getNode(5); /*    4 5 6 7       */
	root->right->left = getNode(6);
	root->right->right = getNode(7);

	cout << "Preorder Traversal before tree modification:n";
	preorderTraversal(root);

	replaceNodeWithSumUtil(root);

	cout << "\nPreorder Traversal after tree modification:n";
	preorderTraversal(root);

	return 0;
}

/* C++ program for special order traversal */
#include <iostream>
#include <queue>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
	int data;
	Node *left;
	Node *right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
Node *newNode(int data)
{
	Node *node = new Node;
	node->data = data;
	node->right = node->left = NULL;
	return node;
}

/* Given a perfect binary tree, print its nodes in specific
level order */
void printSpecificLevelOrder(Node *root)
{
	if (root == NULL)
		return;

	// Let us print root and next level first
	cout << root->data;

	// / Since it is perfect Binary Tree, right is not checked
	if (root->left != NULL)
	cout << " " << root->left->data << " " << root->right->data;

	// Do anything more if there are nodes at next level in
	// given perfect Binary Tree
	if (root->left->left == NULL)
		return;

	// Create a queue and enqueue left and right children of root
	queue <Node *> q;
	q.push(root->left);
	q.push(root->right);

	// We process two nodes at a time, so we need two variables
	// to store two front items of queue
	Node *first = NULL, *second = NULL;

	// traversal loop
	while (!q.empty())
 {
	// Pop two items from queue
	first = q.front();
	q.pop();
	second = q.front();
	q.pop();

	// Print children of first and second in reverse order
	cout << " " << first->left->data << " " << second->right->data;
	cout << " " << first->right->data << " " << second->left->data;

	// If first and second have grandchildren, enqueue them
	// in reverse order
	if (first->left->left != NULL)
	{
		q.push(first->left);
		q.push(second->right);
		q.push(first->right);
		q.push(second->left);
	}
 }
}

/* Driver program to test above functions*/
int main()
{
	//Perfect Binary Tree of Height 4
	Node *root = newNode(1);

	root->left	 = newNode(2);
	root->right	 = newNode(3);

	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	root->left->left->left = newNode(8);
	root->left->left->right = newNode(9);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(11);
	root->right->left->left = newNode(12);
	root->right->left->right = newNode(13);
	root->right->right->left = newNode(14);
	root->right->right->right = newNode(15);

	root->left->left->left->left = newNode(16);
	root->left->left->left->right = newNode(17);
	root->left->left->right->left = newNode(18);
	root->left->left->right->right = newNode(19);
	root->left->right->left->left = newNode(20);
	root->left->right->left->right = newNode(21);
	root->left->right->right->left = newNode(22);
	root->left->right->right->right = newNode(23);
	root->right->left->left->left = newNode(24);
	root->right->left->left->right = newNode(25);
	root->right->left->right->left = newNode(26);
	root->right->left->right->right = newNode(27);
	root->right->right->left->left = newNode(28);
	root->right->right->left->right = newNode(29);
	root->right->right->right->left = newNode(30);
	root->right->right->right->right = newNode(31);

	cout << "Specific Level Order traversal of binary tree is \n";
	printSpecificLevelOrder(root);

	return 0;
}

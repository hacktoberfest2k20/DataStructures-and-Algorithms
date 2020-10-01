// C++ implementation to count pairs from two
// BSTs whose sum is equal to a given value x
#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
struct Node {
	int data;
	Node* left, *right;
};

// function to create and return a node of BST
Node* getNode(int data)
{
	// allocate space for the node
	Node* new_node = (Node*)malloc(sizeof(Node));

	// put in the data
	new_node->data = data;
	new_node->left = new_node->right = NULL;
}

// function to count pairs from two BSTs
// whose sum is equal to a given value x
int countPairs(Node* root1, Node* root2, int x)
{
	// if either of the tree is empty
	if (root1 == NULL || root2 == NULL)
		return 0;

	// stack 'st1' used for the inorder
	// traversal of BST 1
	// stack 'st2' used for the reverse
	// inorder traversal of BST 2
	stack<Node*> st1, st2;
	Node* top1, *top2;

	int count = 0;

	// the loop will break when either of two
	// traversals gets completed
	while (1) {

		// to find next node in inorder
		// traversal of BST 1
		while (root1 != NULL) {
			st1.push(root1);
			root1 = root1->left;
		}

		// to find next node in reverse
		// inorder traversal of BST 2
		while (root2 != NULL) {
			st2.push(root2);
			root2 = root2->right;
		}

		// if either gets empty then corresponding
		// tree traversal is completed
		if (st1.empty() || st2.empty())
			break;

		top1 = st1.top();
		top2 = st2.top();

		// if the sum of the node's is equal to 'x'
		if ((top1->data + top2->data) == x) {
			// increment count
			count++;

			// pop nodes from the respective stacks
			st1.pop();
			st2.pop();

			// insert next possible node in the
			// respective stacks
			root1 = top1->right;
			root2 = top2->left;
		}

		// move to next possible node in the
		// inoder traversal of BST 1
		else if ((top1->data + top2->data) < x) {
			st1.pop();
			root1 = top1->right;
		}

		// move to next possible node in the
		// reverse inoder traversal of BST 2
		else {
			st2.pop();
			root2 = top2->left;
		}
	}

	// required count of pairs
	return count;
}

// Driver program to test above
int main()
{
	// formation of BST 1
	Node* root1 = getNode(5); /*			 5	 */
	root1->left = getNode(3); /*		 / \	 */
	root1->right = getNode(7); /*		 3	 7	 */
	root1->left->left = getNode(2); /* / \ / \ */
	root1->left->right = getNode(4); /* 2 4 6 8 */
	root1->right->left = getNode(6);
	root1->right->right = getNode(8);

	// formation of BST 2
	Node* root2 = getNode(10); /*		 10		 */
	root2->left = getNode(6); /*		 / \	 */
	root2->right = getNode(15); /*	 6	 15	 */
	root2->left->left = getNode(3); /* / \ / \	 */
	root2->left->right = getNode(8); /* 3 8 11 18 */
	root2->right->left = getNode(11);
	root2->right->right = getNode(18);

	int x = 16;
	cout << "Pairs = "
		<< countPairs(root1, root2, x);

	return 0;
}

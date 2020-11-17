// C++ program for an efficient solution to check if
// a given array can represent Preorder traversal of
// a Binary Search Tree
#include<bits/stdc++.h>
using namespace std;

bool canRepresentBST(int pre[], int n)
{
	// Create an empty stack
	stack<int> s;

	// Initialize current root as minimum possible
	// value
	int root = INT_MIN;

	// Traverse given array
	for (int i=0; i<n; i++)
	{
		// If we find a node who is on right side
		// and smaller than root, return false
		if (pre[i] < root)
			return false;

		// If pre[i] is in right subtree of stack top,
		// Keep removing items smaller than pre[i]
		// and make the last removed item as new
		// root.
		while (!s.empty() && s.top()<pre[i])
		{
			root = s.top();
			s.pop();
		}

		// At this point either stack is empty or
		// pre[i] is smaller than root, push pre[i]
		s.push(pre[i]);
	}
	return true;
}

// Driver program
int main()
{
	int pre1[] = {40, 30, 35, 80, 100};
	int n = sizeof(pre1)/sizeof(pre1[0]);
	canRepresentBST(pre1, n)? cout << "truen":
							cout << "falsen";

	int pre2[] = {40, 30, 35, 20, 80, 100};
	n = sizeof(pre2)/sizeof(pre2[0]);
	canRepresentBST(pre2, n)? cout << "truen":
							cout << "falsen";

	return 0;
}

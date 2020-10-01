/*
Problem: Given an array and target x, determine wether there are 3 indices i,j,k such that a[i]+a[j]+a[k]==x .
Complexity: Time:O(N^2) ,Space: O(N)
*/
#include <iostream>
#include <algorithm>

using namespace std;

void naive(int a[], int n, int x)
{
	//brute force all 3 indices in O(N^3)
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (i != j && j != k && k != i)
				{
					if (a[i] + a[j] + a[k] == x)
					{
						cout << "YES\n";
						return;
					}
				}
			}
		}
	}
	cout << "NO\n";
}

void efficient(int a[], int n, int x)
{
	//alternatively , we can sort the array, fix j and try to find i and k;
	// this will be O(NlogN)+O(N^2)= O(N^2)
	sort(a, a + n);
	for (int j = 1; j < n - 1; j++)
	{
		/*
		for each index j, we are trying to find i to its left and k to its right .
		*/
		int i = 0, k = n - 1;
		while (i < j && j < k)
		{
			if (a[i] + a[k] == x - a[j])
			{
				cout << "YES\n";
				return;
			}
			else if (a[i] + a[k] > x - a[j])
			{
				k--;
			}
			else
			{
				i++;
			}
		}
	}
	cout << "NO\n";
}

int main()
{
	int n, x;
	cin >> n >> x;
	int a[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	efficient(a, n, x);
	return 0;
}
// C++ program to find max value of i*arr[i]
#include <iostream>
using namespace std;

// Returns max possible value of i*arr[i]
int maxSum(int arr[], int n)
{
	// Find array sum and i*arr[i] with no rotation
	int arrSum = 0; // Stores sum of arr[i]
	int currVal = 0; // Stores sum of i*arr[i]
	for (int i=0; i<n; i++)
	{
		arrSum = arrSum + arr[i];
		currVal = currVal+(i*arr[i]);
	}

	// Initialize result as 0 rotation sum
	int maxVal = currVal;
    //cout<<arrSum;
	// Try all rotations one by one and find
	// the maximum rotation sum.

	for (int j=1; j<n; j++)
	{
		currVal = currVal + arrSum-n*arr[n-j];

		if (currVal > maxVal)
			maxVal = currVal;
	}

	// Return result
	return maxVal;
}

// Driver program
int main(void)
{
    int arr[] = {10, 1, 2 };
	//int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "\nMax sum is " << maxSum(arr, n);
	return 0;
}

/*
// C++ program to find maximum sum of all
// rotation of i*arr[i] using pivot.
#include <iostream>
using namespace std;

// fun declaration
int maxSum(int arr[], int n);
int findPivot(int arr[], int n);

// function definition
int maxSum(int arr[], int n)
{
	int sum = 0;
	int i;
	int pivot = findPivot(arr, n);

	// difference in pivot and index of
	// last element of array
	int diff = n - 1 - pivot;
	for(i = 0; i < n; i++)
	{
		sum = sum + ((i + diff) % n) * arr[i];
	}
	return sum;
}

// function to find pivot
int findPivot(int arr[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(arr[i] > arr[(i + 1) % n])
			return i;
	}
}

// Driver code
int main(void)
{

	// rotated input array
	int arr[] = {8, 3, 1, 2};
	int n = sizeof(arr) / sizeof(int);
	int max = maxSum(arr, n);
	cout << max;
	return 0;
}

// This code is contributed by Shubhamsingh10

*/

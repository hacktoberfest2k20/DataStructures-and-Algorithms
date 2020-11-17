/*insertion sort is a simple sorting algorithm in which the array us split into a sorted adn unsorted part.
Values from the unsorted part are picked and placed at correct position in sorted part*/
//Time Complexity: O(n*2)

#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n]; //array of size n
    for (int i = 0; i < n; i++)
        cin >> a[i];

    insertionSort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}

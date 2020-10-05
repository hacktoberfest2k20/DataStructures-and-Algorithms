//Selection Sort
//Time Complexity: O(n^2)
//Auxiliary Space: O(1)

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void PrintArray(vector<int> &arr)
{
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;
}

void SelectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int temp = arr[i];
        int loc = i;

        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < temp)
            {
                temp = arr[j];
                loc = j;
            }
        }

        temp = arr[loc];
        arr[loc] = arr[i];
        arr[i] = temp;
    }

    cout << "Array after sorting:" << endl;
    PrintArray(arr);
}

int main(int args, char **argv)
{
    int n;
    cout << "Enter size of Array:";
    cin >> n;

    vector<int> arr(n, 0);

    //Creates a Array containing randomly generated Integers upto 10000
    for (int i = 0; i < n; i++)
        arr[i] = (rand() % 10000) + 1;

    cout << "Initial Array:" << endl;
    PrintArray(arr);

    SelectionSort(arr);
}
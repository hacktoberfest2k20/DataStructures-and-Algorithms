/*

Time Complexity - O(nlog(n)) 
Space Complexity - O(n)

n is the number of elements in given array

*/

// C++ program for Merge Sort
#include <iostream>
#include <vector>
using namespace std;
 
//merge function merges two segments of arr (arr[l...mid] and arr[mid+1...r])
void merge(vector<int>&arr,int l,int r) {
    int mid = (l+r)/2;
    vector<int>left,right;
    //Copy data from arr[l...mid] to left
    for(int i=l;i<=mid;i++) {
        left.push_back(arr[i]);
    } 
    //Copy data from arr[mid+1...r] to right
    for(int i=mid+1;i<=r;i++) {
        right.push_back(arr[i]);
    }
    //i represet the pointer to left and j represet pointer to right vector
    int i = 0, j = 0;
    for(int k=l;k<=r;k++) {
        if(i == left.size()) arr[k] = right[j++];
        else if(j == right.size()) arr[k] = left[i++];
        else if(left[i] > right[j]) arr[k] = right[j++];
        else arr[k] = left[i++];
    }
}
 
//mergeSort is a recursive function to sort a segment of arr from l to r
void mergeSort(vector<int>&arr,int l,int r) {
    if(l == r) return;
    int mid = (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,r);
}

 
// Driver code
int main()
{
    vector<int>arr = {1,24,4,-1,34};
 
    cout << "Given array is \n";
    for(auto u:arr) {
        cout<<u<<' ';
    }
    cout<<"\n";
 
    mergeSort(arr, 0, arr.size()-1);
 
    cout << "\nSorted array is \n";
    for(auto u:arr) {
        cout<<u<<' ';
    }
    cout<<"\n";

    return 0;
}




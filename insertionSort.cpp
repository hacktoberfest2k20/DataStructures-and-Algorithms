#include<iostream>
using namespace std;
   int comparisons = 0;
    int pass = 0;

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void insertSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  

        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
            comparisons = comparisons+1;
        }  
        arr[j + 1] = key;  
        pass = pass+1; 
    } 
    
} 
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];   
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   insertSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
   cout<<"No. of comparisons "<<comparisons<<"\n";
   cout<<"Your array is sorted in "<<pass<<" pass";
}

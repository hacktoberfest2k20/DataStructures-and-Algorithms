#include<iostream>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
int main()
{
int length,k ;
cout<<"Program to Find the Kth largest and Kth smallest number in an array\n\n";
cout<<"\n Enter the value of k : ";
cin>>k;
cout<<"\n Enter the total size of the array : ";
cin>>length;

int a[length];
cout<<"\n Input the elements in the array :\n";
for(int i=0;i<length;i++)
{
  cout<<"\n a["<<i<<"] = ";
  cin>>a[i];
}
selectionSort(a,length);

for(int i=0;i<length;i++)
{
  cout<<"\n a["<<i<<"] = "<<a[i];
}
cout<<"\n the "<<k<<"th largest :"<<a[length-k];
cout<<"\n the "<<k<<"th smallest:"<<a[k-1];



cout<<"\n\nProgram ends here !!";
return 0;
}

//isertion sort algorithm
//Time Complexity o(n*2)
# include <iostream>
using namespace std;

void insertsort(int arr[],int n)
{
    int i,j;
    for ( i = 0; i <= n-1; i++)
    {
       int min=arr[i];
       j=i-1;
       while (j>=0 && arr[j]>min)
       {
           arr[j+1]=arr[j];
           j=j-1;
       }
        arr[j+1]=min;
    }   
        
    
    for ( i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
}

int main()
{
    int i,arr[100],n;
    cin>>n;
    for ( i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    insertsort(arr,n);
    return 0;
}
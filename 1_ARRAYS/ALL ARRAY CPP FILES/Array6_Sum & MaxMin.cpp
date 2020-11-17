#include<iostream>
using namespace std;
int main()
{
int arr[4]={100,20,30,400};
int sum=0,min=arr[0],max=arr[0];
cout<<"Elements in an array : ";
for(int i=0;i<4;i++)
{
    cout<<arr[i]<<"\t";
    sum=sum+arr[i];
}
cout<<"\n\nSum of all array elements : "<<sum;
cout<<"\n";

for(int i=0;i<4;i++)
{
    if(arr[i]<min)
    {   min=arr[i];
    }

    if(arr[i]>max)
    {   max=arr[i];
    }

}
        cout<<"\n\nMinimum element in an array : "<<min ;
        cout<<"\n";
        cout<<"\n\nMaximum element in an array : "<<max ;
        cout<<"\n\n\n";

}

#include<iostream>
using namespace std;
int main()
{
int arr[4]={100,-20,30,400};
int neg=0,pos=0;
cout<<"Elements in an array : ";
for(int i=0;i<4;i++)
{
    cout<<arr[i]<<"\t";
    if(arr[i]<0)
    {
        neg++;
    }
    if(arr[i]>0)
    {
        pos++;
    }
}
cout<<"\n\nNegative array elements : "<<neg;
cout<<"\n\nPositive array elements : "<<pos;

cout<<"\n";
}

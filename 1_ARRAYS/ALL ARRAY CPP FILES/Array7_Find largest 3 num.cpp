/* Problem Statement - Given an array with all distinct elements, find the largest three elements.
                        Input: arr[] = {10, 4, 3, 50, 23, 90}
                        Output: 90, 50, 23
*/

#include<iostream>
using namespace std;

int larg3(int arr[],int n)
{      int first,second,third    ;
       first=second=third=arr[0] ;
    for(int i=1;i<n;i++)
    {
       if(arr[i]>first)
       {    third = second ;
           second = first ;
            first = arr[i] ;

       }
       else if(arr[i]>second)
       {   third = second ;
           second=arr[i];
       }
       else
       {
           third=arr[i];
       }

    }
    cout<<first<<" > "<<second<<" > "<<third;
}

int main()
{
int length1,i,j,sum ;
cout<<"Program to find the largest three elements.\n\n";

cout<<"\n Enter the size of the array : ";
cin>>length1;

int a1[length1];

cout<<"\n Input the elements in the array :\n";
for(int i=0;i<length1;i++)
{
  cout<<"\t a["<<i<<"] = ";
  cin>>a1[i];
}
cout<<"\n\n\n Largest three elements are given below:";
larg3(a1,length1);

cout<<"\n\n\nProgram ends here !!";
return 0;
}

/* Problem Statement -

You are given a list of n-1 integers and these integers are in the range
of 1 to n. There are no duplicates in the list. One of the integers is
missing in the list. Write an efficient code to find the missing integer.
*/

#include<iostream>
using namespace std;

int missing(int arr[],int n)
{   int sum=0;
    for(int i=0;i<n;i++)
    { sum= sum + arr[i];
    }
    int realsum=(n*(n+1)/2);
    int miss=realsum-sum;
    return miss;
}
int main()
{
int length1,i,j ;
cout<<"Program to find the missing integer.\n\n";

cout<<"\n Enter the size of the array : ";
cin>>length1;

int a1[length1];

cout<<"\n Input the elements in the array :\n";
for(int i=0;i<length1;i++)
{
  cout<<"\t a["<<i<<"] = ";
  cin>>a1[i];
}
cout<<"\n Displaying the elements in the Original array :\n";

for(int i=0;i<length1;i++)
{
  cout<<"\n a["<<i<<"] = "<<a1[i];
}
int miss =missing(a1,length1);
cout<<"\n\n\n Missing element in the above array is :"<<miss;

cout<<"\n\nProgram ends here !!";
return 0;
}

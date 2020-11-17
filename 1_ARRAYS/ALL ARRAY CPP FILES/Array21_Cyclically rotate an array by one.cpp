/* Write a program to cyclically rotate an array by one. */

#include<iostream>
using namespace std;

void rotate(int arr[], int n)
{
    int last=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[0]=last;
}

int main()
{
int length1,i,j ;
cout<<"Program to cyclically rotate an array by one.\n\n";

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
rotate(a1,length1);
cout<<"\n Displaying the elements in the array rotated by one:\n";

for(int i=0;i<length1;i++)
{
  cout<<"\n a["<<i<<"] = "<<a1[i];
}




cout<<"\n\nProgram ends here !!";
return 0;
}

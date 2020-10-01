#include<iostream>
using namespace std;

int main()
{
int length,k ;
cout<<"Program to sort without sorting algorithm in an array\n\n";

cout<<"\n Enter the total size of the array : ";
cin>>length;

int a[length];
cout<<"\n Input the elements in the array :\n";
for(int i=0;i<length;i++)
{
  cout<<"\n a["<<i<<"] = ";
  cin>>a[i];
}
int c0=0,c1=0,c2=0;
for(int i=0; i<length;i++)
{
    if(a[i]==0)
    {
        c0++;
    }
    if(a[i]==1)
    {
        c1++;
    }
    if(a[i]==2)
    {
        c2++;
    }
}
int i=0;
while(c0>0)
{
   a[i]=0;
   i++;
   c0--;
}
while(c1>0)
{
   a[i]=1;
   i++;
   c1--;
}
while(c2>0)
{
   a[i]=2;
   i++;
   c2--;
}

cout<<"\n Displaying the elements in the array :\n";
for(int i=0;i<length;i++)
{
  cout<<"\n a["<<i<<"] = "<<a[i];
}

cout<<"\n\nProgram ends here !!";
return 0;
}

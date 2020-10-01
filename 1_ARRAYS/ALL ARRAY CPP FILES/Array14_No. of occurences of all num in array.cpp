#include<iostream>
using namespace std;

int main()
{
int length,k ;
cout<<"Program to Find the number of occurrences of all number in an array\n\n";
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

cout<<"\n Display all the elements in the array :\n";
for(int i=0;i<length;i++)
{
  cout<<"\n a["<<i<<"] = "<<a[i];
}

for(int i=0;i<length;i++)
{   int count=1;
    if(a[i]!=-1)
    {
        for(int j=i+1;j<length;j++)
        {
           if(a[i]==a[j])
           {
               count=count+1;
               a[j]=-1;
           }
        }
        if(count>0)
        {
           cout<<"\n\t Count of "<<a[i]<<" : "<<count;
        }

    }
}

cout<<"\n\nProgram ends here !!";
return 0;
}

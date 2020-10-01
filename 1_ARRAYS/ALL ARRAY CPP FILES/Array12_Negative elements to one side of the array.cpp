#include<iostream>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main()
{

int length,k ;
cout<<"Program to sort negative elements to one side of the array\n\n";

cout<<"\n Enter the total size of the array : ";
cin>>length;

int a[length];

cout<<"\n Input the elements in the array :\n";
for(int i=0;i<length;i++)
{
  cout<<"\n a["<<i<<"] = ";
  cin>>a[i];
}

int j=0;

for(int i=0; i<length;i++)
{
    if(a[i]<0)
    {   
	if(i!=j)
        {
             swap(a[i],a[j]);
        }
        j++;
    }

}

cout<<"\n Displaying the elements in the array :\n";
for(int i=0;i<length;i++)
{
  cout<<"\t "<<a[i];
}

cout<<"\n\nProgram ends here !!";
return 0;

}
	
/* 
meh-MAX ENDING HERE
msf- Max So Far

*/

#include<iostream>
using namespace std;

void lcsa(int arr[], int n)
{
    int msf=0, meh=0;
    for(int i=0;i<n;i++)
    {
        meh=meh+arr[i];
        if(meh<0){ meh=0 ;}
        if(meh>msf){ msf=meh ;}
    }
    cout<<"\n\n Largest contiguous sum : "<<msf;
}

int main()
{
int length1,i,j ;
cout<<"Program to Largest sum contiguous Subarray.\n\n";

cout<<"\n Enter the size of the array : ";
cin>>length1;

int a1[length1];

cout<<"\n Input the elements in the array :\n";
for(int i=0;i<length1;i++)
{
  cout<<"\t a["<<i<<"] = ";
  cin>>a1[i];
}

lcsa(a1,length1);

cout<<"\n\nProgram ends here !!";
return 0;
}

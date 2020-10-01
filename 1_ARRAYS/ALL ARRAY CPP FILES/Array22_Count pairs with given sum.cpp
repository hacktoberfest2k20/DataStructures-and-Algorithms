/* Problem Statement - Find all pairs on integer array whose sum is equal to given number.
*/

#include<iostream>
using namespace std;

int pairs(int arr[],int n, int s)
{   int count=0,tsum=0;
    for(int i=0;i<n;i++)
    {
       for(int j=i+1;j<n;j++)
        {
            tsum=arr[i]+arr[j];
            if(tsum==s)
            {   cout<<" "<<arr[i]<<" , "<<arr[j]<<"\n";
                count++; tsum=0;
            }
        }
    }

    return count;
}
int main()
{
int length1,i,j,sum ;
cout<<"Program to Count pairs with given sum.\n\n";

cout<<"\n Enter the size of the array : ";
cin>>length1;
cout<<"\n Enter the sum : ";
cin>>sum;
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


cout<<"\n\n Pairs with given sum "<<sum<<" are shown below :-\n ";
int pcount =pairs(a1,length1,sum);
cout<<"\n\n\n Pairs Count :"<<pcount;

cout<<"\n\nProgram ends here !!";
return 0;
}

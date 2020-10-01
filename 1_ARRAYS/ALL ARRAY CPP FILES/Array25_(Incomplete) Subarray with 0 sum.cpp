/* Problem Statement - Find if there is any subarray with sum equal to zero.  4 3 -2 -1 -4
*/

#include<iostream>
using namespace std;

int sub0sum(int arr[],int n)
{   int tsum=0;

       for(int j=0;j<n;j++)
        {
            tsum = tsum + arr[j];
            if(tsum==0)
            {
                cout<<"Yes !! It exists..";
            }
        }
}
int main()
{
int length1,i,j,sum ;
cout<<"Program to Count pairs with given sum.\n\n";

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
int sub0sum(a1,length1);
//cout<<"\n\n\n Pairs Count :"<<pcount;
//cout<<"\n Pairs with sum "<<sum<<" are :"<<pair1;
cout<<"\n\nProgram ends here !!";
return 0;
}

/* Problem Statement - Rearrange the array in alternating positive and negative items with O(1) extra space.
                       Input  : arr[]={1,5,6,-3,9,-8,-7}  ---> { -3,-8,-7,1,9,5,6 }
                       Output : arr[]={-3,1,-8,5,-7,6,9}
*/
#include<iostream>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int rearrange(int arr[],int n)
{   int j=0;
    for(int i=0 ;i<n ;i++)
    {
        if(arr[i]<0)
            {
                if(i!=j)
                {
                    swap(arr[i],arr[j]);
                }
                j++;
            }
    }
    cout<<"\n Displaying the elements in the neg at left array :\n";

    for(int i=0;i<n;i++)
    {
      cout<<"\n a["<<i<<"] = "<<arr[i];
    }
    /*                        Input  : arr[]={1,5,6,-3,9,-8,-7}  ---> { -3,-8,-7,1,9,5,6}  i=1 ; k=4
                       Output : arr[]={-3,1,-8,5,-7,6,9}              { -7,9,-3,1,-8,5,6}
    */
    for(int i=0,k=2;i<n && k<n ;i=i+1,k=k+2)
    {   if(i!=-1)
        { swap(arr[i],arr[k]); }
    }

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
//cout<<"\n\n\n Largest three elements are given below:";
rearrange(a1,length1);
cout<<"\n Displaying the elements in the rearranged array :\n";

for(int i=0;i<length1;i++)
{
  cout<<"\n a["<<i<<"] = "<<a1[i];
}
cout<<"\n\n\nProgram ends here !!";
return 0;
}

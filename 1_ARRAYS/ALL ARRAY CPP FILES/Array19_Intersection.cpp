/* Array_Intersection Program */

#include<iostream>
using namespace std;

int main()
{
int length1,length2,i,j ;
cout<<"Intersection of two arrays Program\n\n";

cout<<"\n Enter the size of the array 1: ";
cin>>length1;
cout<<"\n Enter the size of the array 2: ";
cin>>length2;

int a1[length1];  int a2[length2];

cout<<"\n Input the elements in the array 1:\n";
for(int i=0;i<length1;i++)
{
  cout<<"\t a["<<i<<"] = ";
  cin>>a1[i];
}
cout<<"\n Input the elements in the array 2:\n";
for(int j=0;j<length2;j++)
{
  cout<<"\t a["<<j<<"] = ";
  cin>>a2[j];
}
cout<<"\n Displaying the elements in the Intersection array :\n";


for(i=0;i<length1;i++)
{
    for(j=0;j<length2;j++)
   {
        if(a1[i]==a2[j])
        {
            cout<<a1[i]<<"\t";

        }
   }
}




cout<<"\n\nProgram ends here !!";
return 0;
}

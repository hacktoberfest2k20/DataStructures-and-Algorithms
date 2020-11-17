#include<iostream>
using namespace std;

int main()
{
int length,num ;
cout<<" Hello User !! This is Reverse Array Program \n\n";

cout<<"\n Enter the total size of the array : ";
cin>>length;
int a[length];
cout<<"\n Input the elements in the array :\n";
for(int i=0;i<length;i++)
{
  cout<<"\n a["<<i<<"] = ";
  cin>>a[i];
}
 int temp;

for(int i=0,j=length-1;i<j;i++,j--)
{
   temp=a[i];
   a[i]=a[j];
   a[j]=temp;
}
cout<<"\n\n After Reversing Array : \n\n";
for(int i=0;i<length;i++)
{
  cout<<"\n a["<<i<<"] = "<<a[i];
}

cout<<"\n\nProgram ends here !!";
return 0;
}

/*
#include<iostream>
using namespace std ;
int main()
{
  int ar[5],B[5],i,j ;

  cout<<"\n\n\t REVERSE ELEMENTS IN LINEAR ARRAY  "<<endl ;
  cout<<" \n\n\t Enter the elements of Linear Array : \n"<<endl ;

  for(i=0;i<5;i++)
  {
     cout<<"    a["<<i<<"]= " ;
     cin>>ar[i] ;
     cout<<"\n" ;
  }

  for(i=4,j=0;i>=0;i--,j++)
  {
     B[j]=ar[i];
  }
  for(i=0;i<5;i++)
  {
     ar[i]=B[i];
  }
  cout<<"\n\n\t Elements of Linear ARRAY are :\n"<<endl;
  for(i=0;i<5;i++)
  {
     cout<<"    a["<<i<<"]= "<<ar[i]<<"\n"<<endl ;
  }
    return 0;
  }

*/
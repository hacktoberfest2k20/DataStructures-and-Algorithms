#include<iostream>
using namespace std ;
int main()
{
  int n,i,loc,d ;
  cout<<"  \n\n\n\t\t NAME : UTKARSH YADAV "<<endl ;
  cout<<"  \t\t  UID : 17BCS1231     "<<endl ;
  cout<<"\n\n\t DELETING AN ELEMENT IN LINEAR ARRAY " ;
  cout<<"\n\n\n\t     Enter the Size of the Array : ";
  cin>>n;
  int ar[n] ;
  cout<<endl;
  cout<<" \n\n\t Enter the elements of Linear Array : \n"<<endl ;

  for(i=0;i<n;i++)
  {
     cout<<"    a["<<i<<"]= " ;
     cin>>ar[i] ;
     cout<<"\n" ;
  }

  cout<<"\n\n    Enter the Location for Deleting an Element :" ;
  cin>>loc ;
  for(i=loc-1;i<n;i++)
  {
    ar[i]=ar[i+1] ;
  }

cout<<"\n NEW Array is :\n"<<endl  ;
  for(i=0;i<n-1;i++)
  {
     cout<<"     a["<<i<<"]= "<<ar[i]<<"\n"<<endl ;
  }
  return 0;
}

#include<iostream>
using namespace std ;
int main()
{
  int n,i,loc,d ;
  cout<<"  \n\n\n\t\t NAME : UTKARSH YADAV "<<endl ;
  cout<<"  \t\t  UID : 17BCS1231     "<<endl ;
  cout<<"\n\n\t INSERTING AN ELEMENT IN LINEAR ARRAY " ;
  cout<<"\n\n\n\t     Enter the Size of the Array : ";
  cin>>n;
  int ar[n+1] ;
  cout<<endl;
  cout<<" \n\n\t Enter the elements of Linear Array : \n"<<endl ;

  for(i=0;i<n;i++)
  {
     cout<<"    a["<<i<<"]= " ;
     cin>>ar[i] ;
     cout<<"\n" ;
  }

  cout<<"\n\n    Enter the Location for Inserting New Element :" ;
  cin>>loc ;
  cout<<"\n\n    Enter the Element to be INSERTED :" ;
  cin>>d ;

  while(i>=(loc-1))
  {
   ar[i+1]=ar[i] ;
   i=i-1 ;
  }
  ar[loc-1]=d ;
  n=n+1 ;
   cout<<"\n\n\t Elements of Linear ARRAY are :\n"<<endl;
  for(i=0;i<n;i++)
  {
     cout<<"    a["<<i<<"]= "<<ar[i]<<"\n"<<endl ;
  }
    return 0;
  }





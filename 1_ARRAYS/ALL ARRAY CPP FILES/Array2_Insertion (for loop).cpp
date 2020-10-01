#include<iostream>
using namespace std ;
int main()
{
  int n,i,loc,d ;
  cout<<"\n\n\t INSERTING AN ELEMENT IN LINEAR ARRAY " ;
  cout<<"\n\n\n\t     Enter the Size of the Array : ";
  cin>>n;
  int ar[n] ;
  cout<<endl;
  cout<<" \n\n\t Enter the elements of Linear Array : \n"<<endl ;

  for(i=1;i<=n;i++)
  {
     cout<<"    a["<<i<<"]= " ;
     cin>>ar[i] ;
     cout<<"\n" ;
  }

  cout<<"\n\n    Enter the Location for Inserting New Element :" ;
  cin>>loc ;
  cout<<"\n\n    Enter the Element to be INSERTED :" ;
  cin>>d ;

  for(i=n;i>=loc;i--)
  {
      ar[i+1]=ar[i];
      cout<<"ar[i+1]="<<ar[i+1]<<"\t";
      cout<<"ar[i]="<<ar[i]<<"\n";

  }
  ar[loc]=d;
  n=n+1;
cout<<"\n\n\t Displaying Elements of Linear ARRAY :\n"<<endl;
  for(i=1;i<=n;i++)
  {
     cout<<"    a["<<i<<"]= "<<ar[i]<<"\n"<<endl ;
  }
    return 0;
  }

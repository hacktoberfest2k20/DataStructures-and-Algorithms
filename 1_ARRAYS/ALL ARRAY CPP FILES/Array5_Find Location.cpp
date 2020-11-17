#include<iostream>
using namespace std ;
int main()
{
  int n,i,loc ;
  cout<<"  \n\n\n\t\t NAME : UTKARSH YADAV "<<endl ;
  cout<<"  \t\t  UID : 17BCS1231     "<<endl ;
  cout<<"\n\n\t FINDING LOCATION OF AN ELEMENT IN AN ARRAY " ;
  cout<<"\n\n\n\t     Enter Size of the Array : ";
  cin>>n;
  int arr[n] ;
  cout<<endl;
  cout<<" \n\n\t Enter the elements of Array : \n"<<endl ;

  for(i=0;i<n;i++)
  {
     cout<<"    a["<<i<<"]= " ;
     cin>>arr[i] ;
     cout<<"\n" ;
  }

  cout<<" \n\t Enter the Element :";
  cin>>loc;
  int c=0 ;
  for(i=1;i<=n;i++)
  {
   if(arr[i]==loc)
   {
    cout<<"\n\t Location of the given element "<<loc<<" is: "<<i+1<<endl;
    cout<<"\n";
    break;
   }
    c++;

  }
   if(c==n)
    cout<<"Element not found"<<endl;


return 0;
}

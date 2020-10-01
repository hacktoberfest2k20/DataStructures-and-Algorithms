#include<iostream>
using namespace std ;
int main()
{
  int n,i,search,first,last ,middle;
  cout<<"  \n\n\n\t\t NAME : UTKARSH YADAV "<<endl ;
  cout<<"  \t\t  UID : 17BCS1231     "<<endl ;
  cout<<"\t       BINARY SEARCH IN AN ARRAY " ;
  cout<<"\n\n\t    Enter the Size of the Array : ";
  cin>>n;
  int arr[n] ;
  cout<<endl;
  cout<<" \t Enter the elements of Linear Array : "<<endl ;

  for(i=0;i<n;i++)
  {
     cout<<"    a["<<i<<"]= " ;
     cin>>arr[i] ;
     //cout<<"\n" ;
  }

 cout<<" \n\t    Enter searching element: ";
	cin>>search;
	first = 0;
	last = n-1;
	middle = (first+last)/2;
	while (first < last)
	{
		if(arr[middle] < search)
		{
			first = middle + 1;

		}
		else if(arr[middle] == search)
		{
			cout<<"\n\t      "<<search<<" found at location "<<middle+1<<"\n";
			break;
		}
		else
		{
			 last = middle - 1;
		}
		middle = (first + last)/2;
	}
	if(first > last)
	{
		cout<<"\n\t Element Not Found !! "<<search<<" is not present in the array";
	}
	return 0;

}

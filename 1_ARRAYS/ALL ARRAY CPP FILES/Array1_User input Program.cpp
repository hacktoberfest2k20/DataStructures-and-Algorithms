#include<iostream>
using namespace std;

int main()
{   int a[5];
cout<<"Hello User !!\n Enter the elements in an array\n\n";
for(int i=0;i<5;i++)
{
  cout<<"\n a["<<i<<"] = ";
  cin>>a[i];
}
int tsum=0;

 for(int j=0;j<5;j++)
        {
            cout<<"\t j loop sum :"<<tsum<<"\t";
            tsum = tsum + a[j];
            if(tsum==0)
            {
                cout<<"\nYes !! It exists..\n\n";
            }
        }

for(int i=0;i<5;i++)
{
  cout<<"\n a["<<i<<"] = "<<a[i];
}

cout<<"Program ends here !!";
return 0;
}

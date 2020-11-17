#include<iostream>
using namespace std;
int main()
{
    // Pattern 1
            cout<<"Pattern 1\n\n";
    for (int i=1 ;i<=6;i++)
    {
        for(int j=1 ;j<=i;j++)
            {
                cout<<"* ";
            }
            cout<<"\n";
    }

            // Pattern 2
                    cout<<"\n\n\n\n";
             cout<<"Pattern 2\n";
    for (int i=1 ;i<=4;i++)
    {
        for(int j=1 ;j<=4;j++)
            {
                if((i+j)>=5)
                {
                cout<<"* ";
                }
                else{
                    cout<<"  ";

                }
            }
            cout<<"\n";
    }
        // Pattern 3
        cout<<"\n\n\n\n";
        cout<<"Pattern 3\n";
    for (int i=1 ;i<=4;i++)
    {
        for(int j=1 ;j<=4;j++)
            {
                if(i<=j)
                {
                cout<<"* ";
                }
                else{
                    cout<<"  ";

                }
            }
            cout<<"\n";
    }
    // Pattern 4
            cout<<"\n\n\n\n";
            cout<<"Pattern 4\n";
    for (int i=1 ;i<=4;i++)
    {
        for(int j=1 ;j<=4;j++)
            {
                if(j>i)
                {
                cout<<" ";
                }
                else{
                    cout<<" * ";

                }
            }
            cout<<"\n";
    }
    // Pattern 5
            cout<<"\n\n\n\n";
            cout<<"Pattern 5\n";
    for (int i=1 ;i<=5;i++)
    {

        for(int j=1 ;j<=5;j++)
            {
                cout<<i<<" "<<j<<"\t";
            }
            cout<<"\n";
    }
    // Pattern 6
    cout<<"\n\n\n\n";
    cout<<"Pattern 6\n";
    int count=1;
    for(int i=1 ;i<=5;i++)
    {

        for(int j=1 ;j<=5;j++)
            {
                cout<<count++<<" ";
            }
            cout<<"\n";
    }
// Pattern 7
            cout<<"\n\n\n\n";
            cout<<"Pattern 7\n";
    for (int i=1 ;i<5;i++)
    {
        for(int j=1;j<=5-i;j++)
            {
                cout<<"* ";
            }
            cout<<"\n";
    }
    // Pattern 8
            cout<<"\n\n\n\n";
            cout<<"Pattern 8\n";
    for (int i=1 ;i<5;i++)
    {
        for(int j=1;j<=5-i;j++)
            {
                cout<<"* ";
            }
            cout<<"\n";
    }
        // Pattern 9
            cout<<"\n\n\n\n";
            cout<<"Pattern 9\n";
    for (int i=1,k=0 ;i<=3;i++,k=0)
    {
        for(int j=1;j<=5-i;j++)
            {   cout<<"+";
            }
             while(k != 2*i-1)
               {
                cout << "*";
                ++k;
               }
            cout<<"\n";
    }
            // Pattern 10
            cout<<"\n\n\n\n";
            cout<<"Pattern 10\n";
    for (int i=1 ;i<=3;i++)
    {
        for(int j=1;j<=5;j++)
            {  cout<<"*";
            }
            cout<<"\n";
    }

}

/*
#include<iostream>
using namespace std;
int main()
{ int i,j;
            cout<<"Pattern 7\n";
    for(i=1;i<5;i++)
    {
        for(j=1;j=5-i;j++){
                cout<<"* ";
            }
            cout<<"\n";
    }

}

*/
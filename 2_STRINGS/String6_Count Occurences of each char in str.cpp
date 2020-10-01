/* 1. Write a program to count the number of occurrences of each character in the string and print it. https://contribute.geeksforgeeks.org/wp-admin/post.php?post=1582636&action=edit*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    char str[25]="Geeks for Geeks "  ;
    int a_to_z_series[26]={0};  //initialise each index of array a_to_z_series with 0.
    int i,k;
    cout<<"Program to count the number of occurrences of each character in the string.\n\n ";

    cout<<"String  : "<<str;
    cout<<"\n\nCount of each letter is :-";

    for(i=0;str[i]!='\0';i++)
    {
        if( str[i]>='a' && str[i]<='z')
        {
            k=str[i]-'a';
            a_to_z_series[k]+=1;
        }

        if( str[i]>='A' && str[i]<='Z') //for Capital Letters
        {
            k=str[i]-'A';   // for first iteration k= 'G'-'A' = 6
            a_to_z_series[k]+=1; // for first iteration increments value at a_to_z_series[6].
        }
    }

    for(i=0;i<26;i++)
    {
        if(a_to_z_series[i]>0)
        {   cout<<"\n";
            cout<<char(i+97)<<" : "<<a_to_z_series[i]; //char converts and prints the ASCII value in a_to_z_seriess.
        }
    }

    return 0;
}

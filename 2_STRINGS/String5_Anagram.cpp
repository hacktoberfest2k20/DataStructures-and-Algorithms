/* Write a program to check whether given two strings are anagram or not.*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    char str1[10]="Decimal"  ;
    char str2[10]="medical"  ;
    int a_to_z_series[26]={0};  //initialise each index of array a_to_z_series with 0.
    int i,k;
    cout<<"Program to check whether given two strings are anagram.\n ";

    cout<<"\n String 1 : "<<str1;
    cout<<"\n String 2 : "<<str2;

    for(i=0;str1[i]!='\0';i++)
    {
        if( str1[i]>='a' && str1[i]<='z')
        {
            k=str1[i]-'a';
            a_to_z_series[k]+=1;
        }

        if( str1[i]>='A' && str1[i]<='Z') //for Capital Letters
        {
            k=str1[i]-'A';   // for first iteration k= 'G'-'A' = 6
            a_to_z_series[k]+=1; // for first iteration increments value at a_to_z_series[6].
        }
    }

    /* FOR STRING 2 */
    for(i=0;str2[i]!='\0';i++)
    {
        if( str2[i]>='a' && str2[i]<='z')
        {
            k=str2[i]-'a';
            a_to_z_series[k]-=1;
        }

        if( str2[i]>='A' && str2[i]<='Z') //for Capital Letters
        {
            k=str2[i]-'A';   // for first iteration k= 'G'-'A' = 6
            a_to_z_series[k]-=1; // for first iteration increments value at a_to_z_series[6].
        }
    }
    bool flag=true;
    for(i=0;i<26;i++)
    {
        if(a_to_z_series[i]<0)
        {
            flag=false;
        }

    }
    if(flag==true)
    {
        cout<<"\n\n String 1 and String 2 are anagram.\n\n\n"  ;
    }
    else{
        cout<<"\n\n String 1 and String 2 are not anagram.\n\n\n"  ;
    }
    return 0;
}


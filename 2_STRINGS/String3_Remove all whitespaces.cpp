/* 1. Write a program to remove all whitespaces in a given string. */

#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char str[30]="We will stand_together"  ;
    int len= strlen(str);

    cout<<"Program to remove all whitespaces in a given string.\n\n ";
    cout<<"\nOriginal String  : "<<str;
    cout<<"\nOriginal Length : "<<len;
    int j;
    for(int i=0;i<len;i++)
    {
        if( str[i]==' ' )
        {   for(j=i;j<len;j++)
            {
                str[j]=str[j+1];
            }
            len--;
        }
    }
    cout<<"\n\nString after removing spaces : "<<str;
    cout<<"\nNew Length : "<<len;
    cout<<"\n\n\n";
    return 0;
}

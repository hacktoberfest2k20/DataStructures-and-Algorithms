
/* Write a program to check the palindrome string */

#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

void rev_str(string &s, int len)
{   int j;
    char temp ;
    for(int i=0,j=len-1;i<j;i++,j--)
    {   temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

}

int main()
{
    string str="NamaN"  ;
    string str2=str;
    int length=str.length();
    cout<<"Program to reverse the string in place.\n\n ";
    cout<<"Original String  : "<<str;
    cout<<"\n\n Length : "<<length;
    rev_str(str,length);
    cout<<"\n\n Reversed String : "<<str;
    if(str==str2)
    {
        cout<<"\n\n String is Palindrome.\n\n\n ";
    }
    else{
        cout<<"\n\n String is not Palindrome.\n\n\n ";
    }
    cout<<"\n\n\n";
    return 0;
}

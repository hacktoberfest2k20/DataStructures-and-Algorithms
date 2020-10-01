/* Write a Code to check whether one string is a rotation of another.
String 1 = "abcd "
String 2 = "cdab "
*/

#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

bool isrotate(string s1,string s2)
{
    if(s1.length()!=s2.length())
    {
        return false;
    }
    string concate=s1+s1;  // concat = "abcdabcd "
    cout<<"\n\nConcatenated String :"<<concate;
    if(concate.find(s2))
    {
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    string str1="justdoit"  ;
    string str2="itjustdo";
    cout<<"Program to check whether one string is a rotation of another..\n\n ";
    cout<<"\n String 1 : "<<str1 ;
    cout<<"\n String 2 : "<<str2 ;
    bool value= isrotate(str1,str2);

    if(value)
    {
        cout<<"\n\n Yes, one string is a rotation of another. \n\n\n ";
    }
    else{
        cout<<"\n\n No, one string is not a rotation of another. \n\n\n ";
    }
    return 0;
}

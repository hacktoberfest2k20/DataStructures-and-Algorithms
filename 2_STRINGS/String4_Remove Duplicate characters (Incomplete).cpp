/*Write a program to remove Duplicate characters from the String.
     Input : abcdab
     Output: abcd
*/

#include<bits/stdc++.h> #include<iostream> #include<string.h>
using namespace std;
string &remDuplicate(string &s)
{    int flag=0;
    int len=s.length(); int j;
    for(int i=0;i<len;i++)
    {   cout<<"\n i value :"<<i;
        for(j=i+1;j<len;j++)
        {
            int save=j;
            label:
        if(!s[j]=='\0')
        {
            cout<<"\n\n\n   before i="<<i<<"  j= "<<j;
             cout<<"\t STR before : "<<s;
            if(s[i]==s[j])
            {   cout<<"\n\n   s[i]==s[j]  found here \n\n\n ";
                for(int k = j ; k<len ; k++)
                {
                    s[j]=s[j+1];
                    j=j+1;
                }

            }

            j=save;
            flag++;
            cout<<"\n   after  i="<<i<<"  j= "<<j<<"  s[j] = "<<s[j]<<"  s[j+1] = "<<s[j+1];
            cout<<"  s[i] = "<<s[i];
            cout<<"\n STR after comparison: "<<s;
            cout<<"\n";
            if( s[i]==s[j] && s[j+1]==' ')
            {
                cout<<"NULL WORKS";
                s[j]=s[j+1];
                len=s.length();

            }

            //if(flag==20){break;}
            if(  s[j]==s[j+1] && s[j+1]!='\0' && s[i]==s[j])
            {

               cout<<"\n\n   LABEL found here \n\n\n ";
               goto label;

            }

        }
        }
    }
    return s;
}

int main()
{
    string str1="aeeeeea"  ;
    cout<<"\n Program to  remove Duplicate characters from the String.\n\n ";
    cout<<"\n Original String 1 : "<<str1 ;

    remDuplicate(str1);

    cout<<"\n\n After Removing Duplicate String  : "<<str1;
    cout<<"\n\n\n\n";
}


/* 1. Write a basic program to take input (String) from User and just print it. */

#include<iostream>
#include<string>
using namespace std;

int main()
{
string str3; // using string object of class string
char str1[20],str2[20];  // using char array
cout<<"Program to take input (String) from User and just print it.\n\n";

cout<<"\n Enter the string (inputs only first word using char array): ";
cin>>str1;           // inputs only first word (using char array)
cout<<"\n Enter the string (inputs whole sentence using char array): ";
cin.get(str2,20);   // inputs whole sentence  (using char array)

cout<<"\n Enter the string 3 (using string object): ";
getline(cin,str3);

cout<<"\n Displaying all the strings :\n";
cout<<str1<<"\t"<<str2<<"\t"<<str3;

cout<<"\n\nProgram ends here !!";
return 0;
}



/*
 
Time Complexity - O(n*m)
product of length of two strings

Space Complexity -O(n*m)
product of length of two strings

Algorithm - Dynamic Programming (by using dynamic programing keep storing the length of longest common subsequence(lcs) for every continuous part of string1 for the whole string2.)


*/

#include <bits/stdc++.h>
using namespace std;

    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.length()+1;
        int m=text2.length()+1;
        vector<vector<int>>lcs(n,vector<int>(m,0));
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                if(text1[i]==text2[j])
                {
                    lcs[i][j]=lcs[i+1][j+1]+1;
                }
                else
                {
                    lcs[i][j]=max(lcs[i+1][j],lcs[i][j+1]);
                }  
            }
        }
        return lcs[0][0];
    }





int main()
{
    string  string1,string2;
    cin>>string1>>string2;
    cout<<longestCommonSubsequence(string1,string2);
    return 0;
}
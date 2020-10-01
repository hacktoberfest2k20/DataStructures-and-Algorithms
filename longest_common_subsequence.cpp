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
    string  s1,s2;
    cin>>s1>>s2;
    cout<<longestCommonSubsequence(s1,s2);
    return 0;
}
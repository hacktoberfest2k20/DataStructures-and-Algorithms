/*
Name: Longest Common Subsequence
Time Complexity: O(n*m) where n,m is the length of the strings

Given two sequences, find the length of longest subsequence present in both of them. This code uses the 
memoization technique to determine the solution*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair<int, int> pairii;
typedef vector<int> veci;
typedef set<int> seti;
typedef unordered_set<int> unseti;

const ll MAX1 = 105;

ll dp[MAX1][MAX1];

ll lcs(string s1, string s2, ll n, ll m)
{
    if (n == 0 || m == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    else
    {
        if (s1[n - 1] == s2[m - 1])
            return dp[n][m] = (1 + lcs(s1, s2, n - 1, m - 1));
        else
        {
            return dp[n][m] = max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
        }
    }
}

void solve()
{
    ll n, m, x, temp = 0, rem = 0, sum = 0, sum1 = 0, sum2 = 0, cnt = 0, in, i, j, k, flag = 1;
    string s, s1, s2;
    veci v, e, o, p;
    cin >> n >> m;
    cin >> s1 >> s2;
    memset(dp, -1, sizeof(dp));
    ll ans = lcs(s1, s2, n, m);
    cout << ans << "\n";
}

int main()
{

    /*#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif*/

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
        solve();
    return 0;
}
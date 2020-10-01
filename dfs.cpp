//Depth First Search for a Tree rooted at vertex 0
//Use zero-based indexing
//Complexity : O(V)

/*
Sample input:
5           
0 1
0 2
2 3 
2 4 
Sample Output:
0
1
2
3
4
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int LIM = 100005;
#define int long long
//#define ll long long
#define IOS                     \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define mem(a, b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define sz(x) ((int)(x).size())
#define pii pair<int, int>
#define vi vector<int>
#define endl '\n'
#define pb push_back
#define sp << " " <<
#define ss second
#define ff first
int power(int x, int n)
{
  int res = 1;
  while (n)
  {
    if (n & 1)
    {
      res = res * x % mod;
    }
    x = x * x % mod;
    n >>= 1;
  }
  return (res % mod);
}

const int N = 100005;
vector<int> v[N];

void dfs(int root, int prev)
{
  cout << root << endl;
  // int leaf = 1;
  for (int i = 0; i < v[root].size(); i++)
    if (v[root][i] != prev)
    {
      // leaf=0;
      dfs(v[root][i], root);
    }

  // if(leaf)
  // return;
}

int32_t main()
{
  IOS;

  int n = 0;
  cin >> n; //no of nodes in the graph

  for (int i = 0; i < n - 1; i++)
  {
    int a = 0, b = 0;
    cin >> a >> b;
    // a--;
    // b--;

    v[a].pb(b);
    v[b].pb(a);
  }

  dfs(0, -1);

  return 0;
}
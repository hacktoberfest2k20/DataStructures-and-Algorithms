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
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100005;
vector<int> v[N];

void dfs(int root, int prev)
{
  cout << root << endl;

  for (int i = 0; i < v[root].size(); i++)
    if (v[root][i] != prev)
    {
      dfs(v[root][i], root);
    }
}

int32_t main()
{
  int n = 0;
  cin >> n; //no of nodes in the graph

  for (int i = 0; i < n - 1; i++)
  {
    int a = 0, b = 0;
    cin >> a >> b;

    v[a].push_back(b);
    v[b].push_back(a);
  }

  dfs(0, -1);

  return 0;
}
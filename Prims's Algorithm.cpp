/*Given an undirected, connected and weighted graph G(V, E) with V number of vertices(which are numbered from 0 to V - 1)
 and E number of edges.Find and print the Minimum Spanning Tree(MST) using Prim's algorithm.*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll max(ll a, ll b)
{
    if (a < b)
        return b;
    return a;
}

ll min(ll a, ll b)
{
    if (a < b)
        return a;
    return b;
}

#define here cout << "here\n"
#define pp pair<int, int>
#define vpp vector<pp>
#define vecto vector<ll>
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
#define INF LONG_MAX

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

#define ull unsigned long long int
#define f(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)

ll findMinInd(ll n, bool visited[], ll weight[])
{
    ll mini = INT_MAX, index = -1;
    for (int i = 0; i < n; i++)
    {
        //   cout << weight[i] << " ";
        if (mini > weight[i] && visited[i] == false)
        {
            mini = weight[i];
            index = i;
        }
    }
    return index;
}

void solve()
{
    bool visited[100000];
    ll parent[100000];
    ll weight[100000];

    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    ll v, e;
    cin >> v >> e;

    ll **arr = new ll *[v];
    for (int i = 0; i < v; i++)
    {
        arr[i] = new ll[v];
        for (int j = 0; j < v; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < v; i++)
    {
        weight[i] = INT_MAX;
    }

    for (int i = 0; i < e; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        arr[a][b] = c;
        arr[b][a] = c;
    }

    weight[0] = 0;

    while (1)
    {
        ll index = findMinInd(v, visited, weight);

        if (index == -1)
            break;

        visited[index] = true;

        for (int i = 0; i < v; i++)
        {
            if (weight[i] > arr[index][i] && !visited[i] && arr[index][i] != 0)
            {
                parent[i] = index;
                weight[i] = arr[index][i];
            }
        }
    }

    for (int i = 0; i < v; i++)

    {
        if (parent[i] == -1)
        {
            continue;
        }

        cout << min(i, parent[i]) << " " << max(i, parent[i]) << " " << weight[i] << "\n";
    }
}

int main()
{
    IOS;
    solve();
}

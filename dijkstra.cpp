/*Given an undirected, connected and weighted graph G(V, E) with V number of vertices(which are numbered from 0 to V - 1)
 and E number of edges.Find and print the shortest distance from the source vertex(i.e.Vertex 0) to all other vertices(including 
 source vertex also) using Dijkstra's Algorithm. Print the ith vertex number and the distance from source in one line separated by 
 space. Print different vertices in different lines.*/

#include <iostream>
using namespace std;
#define ll long long

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

#define pp pair<int, int>
#define vpp vector<pp>
#define vecto vector<ll>
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

#define ull unsigned long long int
#define f(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)

// Find the index with minimum weight which is not visited
ll findMinInd(ll n, bool visited[], ll weight[])
{
    ll mini = INT_MAX, index = -1;
    for (int i = 0; i < n; i++)
    {
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
    ll weight[100000];
    memset(visited, false, sizeof(visited));

    // INPUT
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
    ll ans[v];

    while (1)
    {
        ll index = findMinInd(v, visited, weight);

        if (index == -1)
            break;

        visited[index] = true;
        ans[index] = weight[index];

        for (int i = 0; i < v; i++)
        {
            if (weight[i] > weight[index] + arr[index][i] && !visited[i] && arr[index][i] != 0)
            {
                weight[i] = weight[index] + arr[index][i];
            }
        }
    }

    // OUTPUT
    for (int i = 0; i < v; i++)
    {
        cout << i << " " << ans[i] << "\n";
    }
}

int main()
{
    IOS;
    solve();
}

/*Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and 
E number of edges.Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.*/

#include <iostream>
#include <string.h>
#include <utility>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <set>
#include <math.h>
#define pp pair<int, int>
#define vpp vector<pp>
#define vecto vector<ll>
#define ll long long
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
using namespace std;
ll X[] = {-1, 1, 0, 0};                // 4
ll Y[] = {0, 0, -1, 1};                // 4
ll XX[] = {-1, 1, 0, 0, -1, 1, -1, 1}; // 8
ll YY[] = {0, 0, -1, 1, -1, 1, 1, -1}; // 8
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

#define ull unsigned long long int
#define f(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)

ll vert[100010];
ll parent[100010];
vector<vector<pp>> v(100010);
vector<pair<ll, pp>> ans;
bool sortby(pair<ll, pp> &a, pair<ll, pp> &b)
{
    return a.ff < b.ff;
}

ll Find_parent(ll a)
{
    if (parent[a] != a)
    {
        return Find_parent(parent[a]);
    }
    else
    {
        return a;
    }
}

void kruskal(ll vertices, queue<pair<ll, pp>> q, ll &count, ll &sum)
{
    if (count >= vertices)
        return;

    if (q.empty())
        return;

    pair<ll, pp> top = q.front();
    q.pop();

    ll parent1 = Find_parent(top.ss.ss);
    ll parent2 = Find_parent(top.ss.ff);

    if (parent1 == parent2)
    {
        vert[top.ss.ff] = 1;
        vert[top.ss.ss] = 1;
        count++;
    }
    else
    {
        vert[top.ss.ff] = 1;
        vert[top.ss.ss] = 1;

        parent[parent1] = parent2;
        count++;

        ans.pb(top);

        //parent[top.ss.ff] = top.ss.ss;
    }
    /*
    for (int i = 0; i < vertices; i++)
    {
        cout << parent[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < vertices; i++)
    {
        cout << vert[i] << ' ';
    }
    cout << "\n";
*/
    kruskal(vertices, q, count, sum);
    return;
}

void solve()
{
    ll vertices, e;
    cin >> vertices >> e;
    memset(vert, 0, sizeof(vert));

    for (int i = 0; i <= 100001; i++)
    {
        parent[i] = i;
    }

    vector<pair<ll, pp>> order;

    for (int i = 0; i < e; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].pb(mp(b, c));
        v[b].pb(mp(a, c));
        order.pb(mp(c, mp(a, b)));
    }

    sort(order.begin(), order.end(), sortby);
    queue<pair<ll, pp>> q;

    for (int i = 0; i < order.size(); i++)
    {
        q.push({order[i].ff, {order[i].ss.ff, order[i].ss.ss}});
    }

    ll count = 0, sum = 0;

    kruskal(vertices, q, count, sum);
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].ss.ff <= ans[i].ss.ss)
            cout << ans[i].ss.ff << " " << ans[i].ss.ss << " " << ans[i].ff << "\n";
        else
        {
            cout << ans[i].ss.ss << " " << ans[i].ss.ff << " " << ans[i].ff << "\n";
        }
    }
}

int main()
{
    IOS;
    solve();
}

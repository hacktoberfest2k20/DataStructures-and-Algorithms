/*==========================================================================*/
/*
   The time complexity is O(ElogE) or O(ElogV) where E is no of edges and V is the number of verties.
   The space complexity is O(V+E) 
*/
/*--------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
using db = double; 
using str = string; 
 
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
 
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;
 
#define tcT template<class T
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
 

#define mp make_pair
#define f first
#define s second

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);

int findRoot(int node, int parent[])
{
    
    while (parent[node] != node) {
        parent[node] = parent[parent[node]];
        node = parent[node];
    }

    return node;
}

void unionSets(int node1, int node2, int parent[])
{
    // Find root of set, node1 belongs to
    int p1 = findRoot(node1, parent);

    // Find root of set, node2 belongs to
    int p2 = findRoot(node2, parent);

    // Make parent of p1 as p2, to join two sets
    parent[p1] = parent[p2];
}

// Function to implement the kruskal's MST Algorithm
int kruskalMST(pair<int,pi > graph[],
               int V, int E)
{
     int parent[V];

     for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int u, v, cost, minCost = 0;

    for (int i = 0; i < E; i++) {
        u = graph[i].second.first;
        v = graph[i].second.second;
        cost = graph[i].first;
        if (findRoot(u, parent) != findRoot(v, parent)) {
            minCost += cost;
            unionSets(u, v, parent);
        }
    }

    return minCost;
}

// Driver Code
int main()
{
    
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph

    
    pair<int, pi > graph[E];

    // add edge 0-1
    graph[0].first = 6;
    graph[0].second.first = 0;
    graph[0].second.second = 1;

    // add edge 0-2
    graph[1].first = 8;
    graph[1].second.first = 0;
    graph[1].second.second = 2;

    // add edge 0-3
    graph[2].first = 15;
    graph[2].second.first = 0;
    graph[2].second.second = 3;

    // add edge 1-3
    graph[3].first = 3;
    graph[3].second.first = 1;
    graph[3].second.second = 3;

    // add edge 2-3
    graph[4].first = 1;
    graph[4].second.first = 2;
    graph[4].second.second = 3;

    // Sort the graph according to weight of edges
    sort(graph, graph + E);

    // Apply Kruskal's Algorithm
    int minCost = kruskalMST(graph, V, E);

    cout << "The cost of MST is: " << minCost;

    return 0;
}

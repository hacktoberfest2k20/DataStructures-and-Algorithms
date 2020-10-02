/*==========================================================================*/
/*
   The time complexity is O(ElogE) or O(ElogV) where E is no of edges and V is the number of verties.
   The space complexity is O(V+E) 
*/
/*--------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

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

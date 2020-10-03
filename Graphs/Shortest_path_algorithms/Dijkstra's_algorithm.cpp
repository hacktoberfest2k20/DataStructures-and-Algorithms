// Dijkstra's Algorithm
//Time Complexity O(V^2) where V ( vertices)  But with min-priority queue it drops down to O(V+ElogV)

// Dijkstra's algorithm has many variants but the most common one is to find the shortest paths from the source vertex to all other vertices in the graph.

// Algorithm Steps:

// 1) Set all vertices distances = infinity except for the source vertex, set the source distance = 0.
// 2) Push the source vertex in a min-priority queue in the form (distance , vertex), as the comparison in the min-priority queue will be according to vertices distances.
// 3) Pop the vertex with the minimum distance from the priority queue (at first the popped vertex = source).
// 4) Update the distances of the connected vertices to the popped vertex in case of "current vertex distance + edge weight < next vertex distance", then push the vertex
// with the new distance to the priority queue.
// 4) If the popped vertex is visited before, just continue without using it.
// 5) Apply the same algorithm again until the priority queue is empty.


// Implementation:
// Assume the source vertex = 1 .
//It's just a simple implementation of dijkstra's algorithm 

#define SIZE 100000 + 1

vector < pair < int , int > > v [SIZE];   // each vertex has all the connected vertices with the edges weights
int dist [SIZE];
bool vis [SIZE];

void dijkstra(){
                                                // set the vertices distances as infinity
    memset(vis, false , sizeof vis);            // set all vertex as unvisited
    dist[1] = 0;
    multiset < pair < int , int > > s;          // multiset do the job as a min-priority queue

    s.insert({0 , 1});                          // insert the source node with distance = 0

    while(!s.empty()){

        pair <int , int> p = *s.begin();        // pop the vertex with the minimum distance
        s.erase(s.begin());

        int x = p.s; int wei = p.f;
        if( vis[x] ) continue;                  // check if the popped vertex is visited before
         vis[x] = true;

        for(int i = 0; i < v[x].size(); i++){
            int e = v[x][i].f; int w = v[x][i].s;
            if(dist[x] + w < dist[e]  ){            // check if the next vertex distance could be minimized
                dist[e] = dist[x] + w;
                s.insert({dist[e],  e} );           // insert the next vertex with the updated distance
            }
        }
    }
}
// Floyd_Warshall's_algorithm
//Time Complexity O(v^3)

// Floyd_Warshall's Algorithm is used to find the shortest paths between between all pairs of vertices in a graph, 
// where each edge in the graph has a weight which is positive or negative. The biggest advantage of using this algorithm is
// that all the shortest distances between any 2  vertices could be calculated in O(v^3) , where V is the number of vertices in a graph.


// The Algorithm Steps:

// For a graph with N vertices:

// 1) Initialize the shortest paths between any  2 vertices with Infinity.
// 2) Find all pair shortest paths that use 0  intermediate vertices, then find the shortest paths that use 1 intermediate vertex and so on.. 
// until using all  N vertices as intermediate nodes.
// 3) Minimize the shortest paths between any  2 pairs in the previous operation.
// 4) For any 2 vertices(i,j)  , one should actually minimize the distances between this pair using the first K nodes, 
// so the shortest path will be: min(dist[i][k]+dist[k][j], dist[i][j]).

// dist[i][k] represents the shortest path that only uses the first K vertices, dist[k][j] represents the shortest path between the pair k,j .
//  As the shortest path will be a concatenation of the shortest path from i to k  , then from k to j  .

for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
        }
    }
}
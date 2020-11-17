// Bellman Ford's Algorithm:

//Time Complexity 0(V.E) ( where V are vertices and E are the edges)

//Space Complexity :
    //   It depends on the way we define it.

    // 1) If we assume that the graph is given, the extra space complexity is O(V) (for an array of distances).

    // 2) If we assume that the graph also counts, it can be O(V^2) for an adjacency matrix and O(V+E) for an adjacency list.

    // They both are "true" in some sense. It's just about what we want to count in a specific problem.


// Bellman Ford's algorithm is used to find the shortest paths from the source vertex to all other vertices in a weighted graph. 
// It depends on the following concept: Shortest path contains at most n-1 edges, because the shortest path couldn't have a cycle.

// So why shortest path shouldn't have a cycle ?
// There is no need to pass a vertex again, because the shortest path to all other vertices could be found without the need for a 
// second visit for any vertices.

// Algorithm Steps:

// The outer loop traverses from 0 : n-1 .
// Loop over all edges, check if the next node distance > current node distance + edge weight, in this case update the next node 
// distance to "current node distance + edge weight".
// This algorithm depends on the relaxation principle where the shortest distance for all vertices is gradually replaced by more
// accurate values until eventually reaching the optimum solution. In the beginning all vertices have a distance of "Infinity", 
// but only the distance of the source vertex = 0, then update all the connected vertices with the new distances (source vertex distance + edge weights), 
// then apply the same concept for the new vertices with new distances and so on.



// Implementation:

// Assume the source node has a number ():

// header files are not included , It is a simple view of bellman ford algorithm

  vector <int> v [2000 + 10];
    int dis [1000 + 10];

    for(int i = 0; i < m + 2; i++){

        v[i].clear();
        dis[i] = 2e9;
    }

   for(int i = 0; i < m; i++){

        scanf("%d%d%d", &from , &next , &weight);

        v[i].push_back(from);
        v[i].push_back(next);
        v[i].push_back(weight);
   }

    dis[0] = 0;
    for(int i = 0; i < n - 1; i++){
        int j = 0;
        while(v[j].size() != 0){

            if(dis[ v[j][0]  ] + v[j][2] < dis[ v[j][1] ] ){
                dis[ v[j][1] ] = dis[ v[j][0]  ] + v[j][2];
            }
            j++;
        }
    }
//Time complexity O(v) where v is the number of  vertices in the graph
//Space complexity O(v)
/*Test case
6 7
0 1 
0 2
0 3
1 3
1 4
2 3
2 5
*/
#include<bits/stdc++.h>

using namespace std;

void bfs(vector< vector<int> >graph, int root,int v)
{
    vector<int>visited(v,0);//keeps track of visited nodes
    queue<int>q;//queue used for bfs
    q.push(root);//pushing the root to the queue
    visited[root]=1;
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        cout<<a<<"\n";
        for(int i=0;i<graph[a].size();i++)
        {
            if(!visited[graph[a][i]])// pushing all the nodes that are not visited and are connected to the node a
                {
                    q.push(graph[a][i]);
                    visited[graph[a][i]]=1;//marks the node as visited
                }
        }
    }
}


int main()
{
    int v,e;//v is the number of vertices or nodes and e is the number of edges
    cin>>v>>e;
    vector< vector<int> >graph;
    graph.resize(v);
    for(int i=0;i<e;i++) // this creates an adjacency list for the  given graph
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(graph,0,v);
    return 0;
}

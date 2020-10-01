#include<bits/stdc++.h>
using namespace std;

vector<bool> visited; 
void depth_first_search(int v,vector<vector<int>>&graph)
{
    if(visited[v])return;   // if already visited then we return
    visited[v] = true;     
    cout<<v<<endl;  // to see which node is visited
    for(int u:graph[v])  
    {
        depth_first_search(u,graph);
    }
}
int main()
{
    int vertices,edges; // assuming vertices start from 0 i.e 0,1,2,......
    cin>>vertices>>edges;
    visited.resize(vertices);
    vector<vector<int>>graph(vertices);
    for(int i =0;i<edges;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    depth_first_search(0,graph);

    return 0;
}
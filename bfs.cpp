#include<bits/stdc++.h>
using namespace std;
//Breadth First Implementation

vector<bool> visited; 


void breadth_first_search(queue<int>&q,vector<vector<int>>&graph)
{
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        int v = q.front();
        visited[v] = true;
        q.pop();
        for(int u : graph[v])
        {
            if(!visited[u])q.push(u);
        }

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
    queue<int>q;
    q.push(0); //starting vertex is 0
    breadth_first_search(q,graph);

    return 0;
}
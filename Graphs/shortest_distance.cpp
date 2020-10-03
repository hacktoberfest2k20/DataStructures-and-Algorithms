#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define ll long long int
using namespace std;

class Graph{
    ll V;
    vector<ll> *arr;
private:
    /* data */
public:
    Graph(ll V);
    void addEdge(ll u, ll v);
    ll dist(ll source, ll target);
};

Graph::Graph(ll V){
    this->V = V;
    arr = new vector<ll>[V];
}

void Graph::addEdge(ll u, ll v){
    arr[u].push_back(v);
}

ll Graph::dist(ll source, ll target){
    ll k = source;
    vector<bool> visit(V, false);
    vector<ll> dest(V, 0);
    visit[source] = true;
    queue<ll> q;
    ll d = 0;
    q.push(source);
    while(!q.empty()){
        d++;
        source = q.front();
        q.pop();
        for(ll i=0; i<arr[source].size(); i++){
            d++;
            if(visit[arr[source][i]]==false){
                dest[arr[source][i]] = dest[source]+1;
                visit[arr[source][i]] = true;
                q.push(arr[source][i]);
            }
        }
        
    }
    return dest[target];
}



int main(int argc, char const *argv[]){
    Graph g(8);
    g.addEdge(0, 1); 
    g.addEdge(0, 3); 
    g.addEdge(1, 2); 
    g.addEdge(3, 4); 
    g.addEdge(3, 7); 
    g.addEdge(4, 5); 
    g.addEdge(4, 6); 
    g.addEdge(4, 7); 
    g.addEdge(5, 6); 
    g.addEdge(6, 7); 
    ll source = 0, target = 6; 
    cout<<"distace from "<<source<<" to "<<target<<" : ";
    cout<<g.dist(source, target)<<endl;
    return 0;
}

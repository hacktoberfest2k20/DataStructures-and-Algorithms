#include<iostream>
#include<list>
#include<queue>
using namespace std;
class Graph
{
private:
    list <int>* adj;
    int v;
    bool cycle_helper(int curr,bool* visited,int parent){
        visited[curr]=true;
        for(auto nbr: adj[curr]){
            if(!visited[nbr]){
                bool found=cycle_helper(nbr,visited,curr);
                if(found)
                    return found;
            }
            else if(nbr != parent)
                return true;

        }
        return false;
    }
public:
    Graph(int n){
        this->v=n;
        adj=new list<int> [n];

    }
    void addEdge(int from, int to){
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    bool cycle_detector(){
        int src=1;
        bool* visited=new bool[v];
        for(int i=0;i<v;++i){
            visited[i]=false;
        }
        return cycle_helper(src,visited,-1);
    }
};

class directedGraph
{
private:
    list <int>* adj;
    int v;
public:
    directedGraph(int n){
        this->v=n;
        adj=new list<int> [n];

    }
    void addEdge(int from, int to){
        adj[from].push_back(to);
    }
    bool cycle_helper(int curr,bool* path,bool* visited){
        visited[curr]=true;
        path[curr]=true;
        for(auto nbr:adj[curr]){
            if(path[nbr] == true)
                return true;
            else if(!visited[nbr]){
                bool found=cycle_helper(nbr,path,visited);
                if(found)
                    return true;
            }
        }
        path[curr]=false;
        return false;
    }
    bool cycle_detector(){
        int src=0;
        bool* path_stack=new bool[v];
        bool* visited=new bool[v];
        for(int i=0;i<v;++i){
            path_stack[i]=false;
            visited[i]=false;
        }
        return cycle_helper(src,path_stack,visited);
    }
    
};




int main()
{   Graph g(5);
    g.addEdge(1,2);
    g.addEdge(3,2);
    g.addEdge(1,3);
    g.addEdge(4,2);
    g.addEdge(3,4);
    cout<<boolalpha<<g.cycle_detector()<<"\n";
    directedGraph h(7);
    h.addEdge(0,1);
    h.addEdge(1,2);
    h.addEdge(1,5);
    h.addEdge(5,6);
    h.addEdge(2,3);
    //h.addEdge(3,4);
    h.addEdge(4,2);
    h.addEdge(4,5);
    cout<<boolalpha<<h.cycle_detector()<<"\n";
    
    return 0;
}

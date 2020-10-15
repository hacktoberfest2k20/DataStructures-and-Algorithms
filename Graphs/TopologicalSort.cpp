
#include <bits/stdc++.h>
using namespace std;

void init(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

bool dfs(int v, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recStack, stack<int>& topologicalOrder){
	visited[v]=true;
	recStack[v]=true;
	for(int child: graph[v]){
		if(recStack[child])
			return false;
		if(visited[child]==false){
			if(dfs(child,graph,visited,recStack,topologicalOrder)==false)
				return false;
		}
	}
	topologicalOrder.push(v);
	recStack[v]=false;
	return true;
}
vector<int> findTopologicalOrder(int numCourses, vector<vector<int>>& graph) {
	
	// traverse the graph and find topological sort
	stack<int> topologicalOrder;
	vector<bool> visited(numCourses);// for visited node
	vector<bool> recStack(numCourses);// for rec stack to check if there is back-edge
	for(int i=0;i<numCourses;i++){
		visited[i]=false;
	}
	// pick any non-visited vertex;
	vector<int> ans;
	for(int i=0;i<numCourses;i++){
		if(visited[i]==false){
			if(dfs(i,graph,visited,recStack,topologicalOrder)==false){// means there is backedge
				return ans;
			}
		}
	}

	if(topologicalOrder.size()!=numCourses)
		return ans;
	while(topologicalOrder.size()!=0){
		ans.push_back(topologicalOrder.top());
		topologicalOrder.pop();
	}
	return ans;
}

int main(){
    int t=1;
    while(t--){
		int n,m,a,b;
		cout<<"Enter Nodes and Edges Count ";
		cin>>n>>m;
		//create graph
		vector<vector<int>> graph(n);
		for(int i=0;i<m;i++){
			cin>>a>>b;
			graph[a].push_back(b);
		}
        vector<int> ans=findTopologicalOrder(n,graph);
        cout<<"The topological sort is as follows\n";
		for(int i:ans)
			cout<<i<<" ";
		cout<<"\n";
	}
}
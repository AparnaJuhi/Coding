#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    void dfs(int V, vector<int> adj[], int s,  int visited[])
    {
        visited[s]++;
        for(int j:adj[s])
        {
            //as graph does not contains any cycle- so without checking visited directly 
            //make recursion calls
            
            dfs(V,adj,j,visited);
            
        }
    }
    //Function to count paths between two vertices in a directed graph.
	int countPaths(int V, vector<int> adj[], int source, int destination)
	{
	   int visited[V];
	   for(int i=0;i<V;i++)
	   {
	       visited[i]=0;
	   }
	   
	   //increment visited, every time the destination is visited
	    dfs(V,adj,source,visited);
	    return visited[destination];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;
    	vector<int> adj[V];
    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		// adj[v].push_back(u);
    	}
    	int source, destination;
    	cin >> source >> destination;
        Solution obj;
        cout<<obj.countPaths(V, adj,source,destination)<<endl;
	}
	return 0;
}  // } Driver Code Ends

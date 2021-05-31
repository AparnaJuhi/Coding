#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool dfs(int V, vector<int>adj[], bool visited[], int s, int parent)
    {
        visited[s]=true;
        for(int u:adj[s])
        {
            if(!visited[u])
            {
                if(dfs(V,adj,visited,u,s))
                return true;
            }
            
            else
            {
                if(u!=parent)
                return true;
            }
        }
        return false;
    }
    
	bool isCycle(int V, vector<int>adj[])
	{
	    //there are two conditions of a cycle- The nodes must be visited.
	    // And it shoudl not be the parent of current node
	    
	    
	    bool visited[V];
	    for(int i=0;i<V;i++)
	    {
	        visited[i]=false;
	    }
	    //Using DFS
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            bool ans=dfs(V,adj, visited,i, -1);
	            //start with the 0th vertex, let its parent be -1;
	            if(ans==true)
	            return true;
	        }
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends

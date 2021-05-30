#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	
	void dfs(int V, vector<bool>&visited, vector<int> adj[], int s,vector<int>&ans)
	{
	    visited[s]=true;
	    ans.push_back(s);
	    for(int i:adj[s])
	    {
	        if(!visited[i])
	        {
	            dfs(V,visited,adj,i,ans);
	        }
	    }
	}
	
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    
	    //Taking care of graph in case its disconnected
	   vector<bool>visited;
	    for(int i=0;i<V;i++)
	    visited.push_back(false);
	    vector<int>ans;
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==false)
	        dfs(V,visited,adj,i,ans);
	    }return ans;
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
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends


 // } Driver Code Ends



class Solution
{
    public:
    
    bool dfs(int V, vector<int> adj[], int s, bool rec[], bool visited[])
    {
        rec[s]=true;
        visited[s]=true;
        for(int u:adj[s])
        {
            if(!visited[u] && dfs(V, adj, u, rec, visited))
            {
                //if unvisited and present i recursion stack
                return true;
                
            }
            else if(rec[u]==true)
            {
                //if it is present in recursion stack
                return true;
                
            }
        }
        rec[s]=false;
        return false;
    }
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// a directed graph has cycle if there's a backedge in current recursion stack
	   	
	   	bool visited[V];
	   	for(int i=0;i<V;i++)
	   	visited[i]=false;
	   	
	   	//make a recursion stack, to track the visited nodes in a recurskon
	   	bool rec[V];
	   	for(int i=0;i<V;i++)
	   	rec[i]=false;
	   	
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(!visited[i])
	   	    {
	   	        if(dfs(V,adj,i,rec,visited))
	   	        return true;
	   	    }
	   	}
	   	return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends

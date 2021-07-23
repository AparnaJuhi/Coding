#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
	public:
	
	int mst( vector<vector<int>> adj[], int V)
	{
	    bool visited[V];
	    int val[V];
	    for(int i=0;i<V;i++)
	    {visited[i]=false;
	    val[i]=INT_MAX;}
	    val[0]=0;
	    int count=0;
	    for(int i=0;i<V;i++)
	    {
	        
	        int minIdx=-1;
	        for(int j=0;j<V;j++)
	        {
	            if(((minIdx==-1) ||val[minIdx]>val[j]) && visited[j]==false)
	            {
	                minIdx=j;
	            }
	        }
	        count+=val[minIdx];
	        visited[minIdx]=true;
	        
	        //now fill the val array a/c to the distrance from minIdx
	        
	        for(vector<int> j: adj[minIdx])
	        {
	            int t=j[0];
                if(!visited[t])
                val[t]=min(j[1], val[t]);
	        }
	        
	    }
	    return count;
	    
	    
	    
	    
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //store edges and its corresponding weight in a map
        
        return mst(adj, V);
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends

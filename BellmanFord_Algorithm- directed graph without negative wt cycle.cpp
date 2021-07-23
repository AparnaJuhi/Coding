#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        
        
        //make a graph of this adj
        int g[V][V];
        //intialise all to INT_MAX;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                g[i][j]=100000000;
            }
        }
        
        for(int i=0;i<adj.size();i++)
        {
            int u=adj[i][0];
            int v=adj[i][1];
            int w=adj[i][2];
            g[u][v]=w;
        }
        bool visited[V];
	   vector<int>val;
	    for(int i=0;i<V;i++)
	    {visited[i]=false;
	    val.push_back(100000000);}
	    val[S]=0;
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
	        
	        for(int j=0;j<V;j++)
	        {
	            if(g[minIdx][j]!=100000000  &&  !visited[j] && val[j]>val[minIdx]+g[minIdx][j])
	            {
                val[j]=val[minIdx]+g[minIdx][j];
	            }
	        }
	        
	    }return val;
	    
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
        vector<vector<int>> adj;
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.bellman_ford(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends

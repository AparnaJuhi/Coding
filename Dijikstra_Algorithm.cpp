#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        bool visited[V];
	   vector<int>val;
	    for(int i=0;i<V;i++)
	    {visited[i]=false;
	    val.push_back(INT_MAX);}
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
	        
	        for(vector<int> j: adj[minIdx])
	        {
	            int t=j[0];
                if(!visited[t])
                val[t]=min(j[1]+val[minIdx], val[t]);
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends

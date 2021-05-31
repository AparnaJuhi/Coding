#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    //find distance of each node from 0
	    int level[V];
	    for(int i=0;i<V;i++)
	    {
	        level[i]=-1;
	    }
	    
	    bool visited[V];
	    for(int i=0;i<V;i++)
	    {
	        visited[i]=false;
	    }
	    
	    level[0]=0;
	    queue<int>q;
	    q.push(0);
	    
	    //used bfs- as it traverses vertices in shortest path manner
	    while(!q.empty())
	       {
	           // now do dfs of each graph and assign levels
	           int t=q.front();
	           q.pop();
	           for(int i:adj[t])
	           {
	               if(!visited[i])
	               {
	                   visited[i]=true;
	                   level[i]=level[t]+1;
	                   q.push(i);
	               }
	           }
	       }
	       if(X<V)
	       return level[X];
	       return -1;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

  // } Driver Code Ends

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
	//Function to return a list containing it distance from node 0.
	

	vector<int>shortestPath(int V, vector<int> adj[])
	{
	    
	    queue<int>q;
	    int visited[V];
	    
	     //make all visited nodes false, as we haven't visited any nodes yet
	    
	    for(int i=0;i<V;i++)
	    visited[i]=false;
	   
	    
	    //lets start with the first node
	    vector<int>dist;
	    for(int i=0;i<V;i++)
	    dist.push_back(INT_MAX);
	    dist[0]=0;
	    q.push(0);
	    vector<int>ans;
	    while(!q.empty())
	    {
	        int i=q.front();
	        q.pop();
	        visited[i]=true;
	       
	        for(int j:adj[i])
	        {
	            if(!visited[j])
	            {
	                q.push(j);
	                dist[j]=dist[i]+1;
	                visited[j]=true;
	            }
	            
	        }
	    }
	    return dist;
	    
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
        vector<int>ans=obj.shortestPath(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends

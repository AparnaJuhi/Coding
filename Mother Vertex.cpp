#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
     void dfs(int V, vector<int> adj[], int s,  int visited[], int &count)
    {
        visited[s]=1;
        count++;
        for(int j:adj[s])
        {
            
            if(!visited[j])
            dfs(V,adj,j,visited,count);
            
        }
    }
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	   int visited[V];
	   for(int i=0;i<V;i++)
	   {
	       visited[i]=0;
	   }
	   
	
	   //coount the number of vertices reached by each node, and then decide mother vertex
	   
	   
	   for(int source=0;source<V;source++)
	    {
	        int count=0;
	        dfs(V,adj,source,visited,count);
	        if(count==V)
	        return source;
	        memset(visited,0,V);//again initialise visited to false
	    }
	    return -1;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends

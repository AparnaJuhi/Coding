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
        //visited array to track nodes covered
        
        int visited[V];
        vector<int> dist;
        for(int i=0;i<V;i++)
        {
            visited[i]=0;
            dist.push_back(INT_MAX);
        }
        
        dist[S]=0;
        for(int i=0;i<V;i++)
        {
            //find the smallest distance vertex which is unvisited
            
            int minIndex=-1;
            int mini=INT_MAX;
            for(int j=0;j<V;j++)
            {
                if(visited[j]==0)
                {
                    if(dist[j]<mini)
                    {
                        mini=dist[j];
                        minIndex=j;
                    }
                }
            }
            
           
            for(vector<int>j:adj[minIndex])
            {
                int edge=j[0];
                int weight=j[1];
                
                if(visited[edge]==0 && dist[edge]>(dist[minIndex]+weight))
                {
                    dist[edge]=(dist[minIndex]+weight);
                }
            }
             visited[minIndex]=1;
            
        }
        return dist;
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

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        
        //mst by prim's algo
        
        //initiaise all edges msp as false
        bool mst[V];
        memset(mst, false, sizeof(mst));
        
        
        //make a key array
        int key[V];
        for(int i=1;i<V;i++)
        key[i]=INT_MAX;
         key[0]=0;
         int result=0;
        for(int i=0;i<V;i++)
        {
            
            //Now select a vertex which has not been visited yet/
            //means its msp value is false.
            
            //And has lowest key
            
            int minindex=-1;
            int mini=INT_MAX;
            for(int j=0;j<V;j++)
            {
               // cout<<key[j]<<" =key[j] and "<<key[minindex]<<"= minindex\n";
                if(mst[j]==false )
                {
                        if(mini>key[j])
                        {minindex=j;
                        mini=key[j];}
                    
                }
                
            }
            
            //j is the minimum index we got
    
            
            int u=minindex;
            //cout<<u<<"\n";
            result+=key[u];
            mst[u]=true;
            for(vector<int> j:adj[u])
            {
                int t=j[0];
                if(!mst[t])
                key[t]=min(j[1], key[t]);
            }
        }
        return result;
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

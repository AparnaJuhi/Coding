//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function Template for C++

class Solution{   
public:
    
    
    long long solve(int V,int E,vector<int> Values,vector<vector<int>> Edges){
      //solve by bfs
      
      long long maxi=0;
      vector<int>adj[V+1];
      for(int i=0;i<Edges.size();i++)
      {
          int u=Edges[i][0];
          int v=Edges[i][1];
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
        
        vector<bool>visited;
        for(int i=0;i<=V;i++)
        visited.push_back(false);
        
        for(int i=1;i<=V;i++)
        {
            long long count=0;
            if(visited[i]==false)
            {
                visited[i]=true;
               
                queue<int>q;
                q.push(i);
                
                while(!q.empty())
                {
                    int t=q.front();
                    q.pop();
                   
                    for(int v:adj[t])
                    {
                        if(visited[v]==false)
                        {
                            q.push(v);
                            
                            visited[v]=true;
                            
                        }
                        
                    }
                    
                     count+=Values[t-1];
                    
                }
                
                maxi=max(count,maxi);
            }
        }
        return maxi;
    }
};


// { Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int V,E;
      cin>>V>>E;
      vector<int> Values(V);
      for(int i=0;i<V;i++)
        cin>>Values[i];
      vector<vector<int>> Edges(E,vector<int>(2));
      for(int i=0;i<E;i++)
        cin>>Edges[i][0]>>Edges[i][1];
      Solution obj;
      long long answer=obj.solve(V,E,Values,Edges);
      cout<<answer<<endl;
  }
}  // } Driver Code Ends

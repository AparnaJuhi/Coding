class Solution {
public:
    
    void dfs(vector<bool>&visited, int s, vector<int>adj[], vector<int>&count)
    {
        visited[s]=true;
        count[s]+=1;
        for(int u:adj[s])
        {
            if(visited[u]==false)
            {
                dfs(visited,u, adj, count);
            }
            else
            {
                count[u]+=1;
            }
        }
    }
    int findCenter(vector<vector<int>>& edges) {
    //if a node is visited n no of times then it is star graph
         int N=edges.size()+1;
    vector<int>count;
        for(int i=0;i<=N;i++)
            count.push_back(0);
    
       vector<int>adj[N+1];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
       
 
     vector<bool>visited;
         for(int i=0;i<=N;i++)
            visited.push_back(0);
    // do dfs
        for(int i=1;i<=N;i++)
        {
           
            dfs(visited, i, adj , count);
        }
        
        int maxii=0;
        int maxind=-1;
        for(int i=1;i<=N;i++)
        {
            if(maxii < count[i])
            {
                maxii=count[i];
                maxind=i;
            }
           
        }
        return maxind;
    }
};

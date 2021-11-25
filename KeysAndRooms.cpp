class Solution {
public:
    void dfs( vector<vector<int>>g, bool visited[], int s)
    {
        visited[s]=true;
        for(int i=0;i<g[s].size();i++)
        {
            if(visited[g[s][i]]==false)
            {
                dfs(g,visited,g[s][i]);
            }
        }
        return;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
     
        int n=rooms.size();
        bool visited[n];
        for(int i=0;i<n;i++)
            visited[i]=false;
        
   
        
            
        dfs(rooms, visited, 0);
        
       for(int i=0;i<n;i++)
        {
           if(visited[i]==false)
               return false;
       }
        return true;
        
    }
};

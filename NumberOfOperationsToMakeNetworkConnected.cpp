class Solution {
public:
   
    void dfs( bool visited[], int s, int n, vector<int>graph[])
    {
        visited[s]=true;
        for(int i:graph[s])
        {
            if( visited[i]==false)
            {
                dfs(visited,i, n,graph);
            }
        }
        return;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() <n-1)
            return -1;
        
        bool visited[n];
        for(int i=0;i<n;i++)
            visited[i]=false;
        vector<int>graph[n];
       
        for(int i=0;i<connections.size();i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        
        int count=0;
        for(int i=0;i<n;i++)
            { 
            if(visited[i]==false)
            {count++;
            dfs(visited,i,n, graph);
            }   
       }
        return count-1;
        
        
    }
};

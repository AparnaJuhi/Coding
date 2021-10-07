class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>&visited)
    {
       
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]=='1' && visited[i][j]==0)
        {
             visited[i][j]=1;
            
                dfs(grid, i+1, j, visited);
            
            //if(visited[i-1][j]==0)
                dfs(grid, i-1, j, visited);
            // if(visited[i][j+1]==0)
                dfs(grid, i,j+1, visited);
             //if(visited[i][j-1]==0)
                dfs(grid, i, j-1, visited);
            
        }
            return;
        
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>visited;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            vector<int>p;
            for(int j=0;j<m;j++)
            {
                p.push_back(0);
            }
            visited.push_back(p);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==0 &&  grid[i][j]=='1')
                {dfs(grid,i,j,visited);
                 count+=1;}
            }
        }
       
       return count;
        
    }
};

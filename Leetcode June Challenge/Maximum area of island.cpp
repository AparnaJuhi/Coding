class Solution {
public:
    int dfs(vector<vector<int>>& grid, int n, int m)
    {
        if(n>=0 && n<grid.size() && m>=0 && m<grid[0].size() && grid[n][m]==1)
        {
            //mark it as visited
            grid[n][m]=0;
            return(1+dfs(grid,n+1,m) + dfs(grid,n-1,m) + dfs(grid,n,m+1)+ dfs(grid,n,m-1));
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //if there is unvisited land
                if(grid[i][j]==1)
                {
                    maxi=max(maxi, dfs(grid, i, j));
                }
            }
        }
        return maxi;
        
    }
};

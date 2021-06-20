class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int mat[m][n];
        if(grid[0][0]!=1)
        mat[0][0]=1;
        else
        mat[0][0]=0;
        for(int i=1;i<n;i++)
        {
            //filling the topmost row
            if(grid[0][i]!=1)
             mat[0][i]=mat[0][i-1];
            else
            {
                mat[0][i]=0;
            }
        }
        for(int i=1;i<m;i++)
        {
            //filling leftmost col
            if(grid[i][0]!=1)
           mat[i][0]=mat[i-1][0];
             else
            {
                mat[i][0]=0;
            }
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    mat[i][j]=0;
                }
                else
                mat[i][j]=(mat[i-1][j]+mat[i][j-1]);
            }
        }
        return mat[m-1][n-1];
    }
};

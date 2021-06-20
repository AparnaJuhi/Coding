class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int mat[m][n];
        mat[0][0]=grid[0][0];
        for(int i=1;i<n;i++)
        {
            //filling the topmost row
           mat[0][i]=mat[0][i-1]+grid[0][i];
        }
        for(int i=1;i<m;i++)
        {
            //filling leftmost col
           mat[i][0]=mat[i-1][0]+grid[i][0];
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                mat[i][j]=min(mat[i-1][j]+grid[i][j], mat[i][j-1]+grid[i][j]);
            }
        }
        return mat[m-1][n-1];
    }
};

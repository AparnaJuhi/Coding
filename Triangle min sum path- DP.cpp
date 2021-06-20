class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //set all the sides of a triangle to 1
        int k=triangle.size();
        int mat[k][k];
        mat[0][0]=triangle[0][0];
        for(int i=1;i<k;i++)
        {
            int t=triangle[i].size();
            mat[i][0]=mat[i-1][0]+triangle[i][0];
            mat[i][t-1]=mat[i-1][t-2]+triangle[i][t-1];
        }
         for(int i=1;i<k;i++)
         {
             int t=triangle[i].size();
            for(int j=1;j<t-1;j++)
            {
                mat[i][j]=min(mat[i-1][j-1],mat[i-1][j])+triangle[i][j];
            }
         }
        int ans=INT_MAX;
        for(int i=0;i<k;i++)
        {
            ans=min(ans,mat[k-1][i]);
        }
        return ans;
        
        
    }
};

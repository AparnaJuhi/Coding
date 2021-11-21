class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
      int dp[mat.size()][mat[0].size()];
        
       
         for(int i=0;i<mat.size();i++)
         {
             for(int j=0;j<mat.size();j++)
               {
                   dp[i][j]=INT_MAX;
               }
         }
        for(int i=0;i<mat.size();i++)
            dp[0][i]=mat[0][i];
        int n=mat.size();
        for(int i=1;i<mat.size();i++)
        {
            for(int j=0;j<mat.size();j++)
            {
                if((j-1) >=0 && (j-1)<n)
                {
                    dp[i][j]=min(dp[i][j], mat[i][j]+ dp[i-1][j-1]);
                }
                if((j+1) >=0 && (j+1)<n)
                {
                    dp[i][j]=min(dp[i][j], mat[i][j]+ dp[i-1][j+1]);
                }
                dp[i][j]=min(dp[i][j], mat[i][j]+ dp[i-1][j]);
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<mat.size();i++)
        {
            ans=min(ans, dp[mat.size()-1][i]);
        }
        return ans;
    }
};

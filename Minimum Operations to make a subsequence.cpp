class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        //find length of target- lcs
        
        //finding lcs
        long long int n=target.size();
        long long int m=arr.size();
        unsigned long long int dp[n+2][m+2];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                    continue;
                }
            }
        }
         for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(target[i-1]==arr[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
     
        //the lcs needed= lcs we want - lcs we found
        return target.size()-dp[n][m];
        
    }
};

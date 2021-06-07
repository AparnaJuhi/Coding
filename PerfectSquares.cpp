class Solution {
public:
    int numSquares(int n) {
        //similar to min coins required to make  a value
        vector<int>arr;
        for(int i=1;i*i<=n;i++)
        {
            arr.push_back(i*i);
        }
        
        int ans=9999999;
        int dp[n+1];
        for(int i=0;i<=n;i++)
            dp[i]=ans;
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<arr.size();j++)
            {
                if(i>=arr[j])
                {
                    dp[i]=min(1+dp[i-arr[j]], dp[i]);
                }
            }
        }
        return dp[n];
    }
};

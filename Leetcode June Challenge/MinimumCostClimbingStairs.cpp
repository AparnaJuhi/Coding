class Solution {
public:
    int minCostClimbingStairs(vector<int>& arr) {
        int n=arr.size();
        int dp[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=INT_MAX;
        }
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=n;i++)
        {
            dp[i]=min(dp[i],min(arr[i-2]+dp[i-2],arr[i-1]+dp[i-1]));
        }
        return dp[n];
        
    }
};

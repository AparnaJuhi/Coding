class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //question similar to max number of coins to make a value
        int dp[n+1];
        for(int i=0;i<=n;i++)
        {
            if(i==x || i==y || i==z)
            dp[i]=1;
            else
            dp[i]=0;
        }
        
        for(int i=0;i<=n;i++)
        {
            if(i>x)
            {
                if(dp[i-x]!=0)
                {
                    dp[i]=max((dp[i-x]+dp[x]) , dp[i]);
                }
                
            }
            if(i>y)
            {
                if(dp[i-y]!=0)
                {
                    dp[i]=max((dp[i-y]+dp[y]) , dp[i]);
                }
                
            }
            if(i>z)
            {
                if(dp[i-z]!=0)
                {
                    dp[i]=max((dp[i-z]+dp[z]) , dp[i]);
                }
                
            }
        }
        
        return dp[n];
    }
};

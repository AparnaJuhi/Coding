long long maximumAmount(int arr[], int n) 
{
    //dp soln
    long long dp[n][n];
    for(int i=0;i<n-1;i++)
    {
       dp[i][i+1]=max(arr[i],arr[i+1]);
    }
   
    
    //now there are two conditions - I can pick ith position or jth positon
    
    //since opponent is also playing smartly so whatever I pick, I will get the minimum from remaining
    //as opponent will try best to increase their score
    
    for(int gap=3;gap<n;gap+=2)
    {
        for(int i=0;i+gap<n;i++)
        {
            int j=i+gap;
            dp[i][j]=max(arr[i]+ min(dp[i+2][j], dp[i+1][j-1]), arr[j]+ min(dp[i+1][j-1], dp[i][j-2]));
        }
    }
    
    return dp[0][n-1];
}

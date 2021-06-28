#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int egg, int f) 
    {
        //by dp
        int dp[f+1][egg+1];
        for(int i=0;i<=egg;i++)
        {
            dp[0][i]=0;//if there are no floors
            dp[1][i]=1;//if there is only one floor
        }
         for(int i=2;i<=f;i++)
        {
            dp[i][0]=0;
            dp[i][1]=i;//if no of egg is 1, then trials will be no of floors
        }
        
        for(int i=2;i<=f;i++)
        {
            for(int j=2;j<=egg;j++)
            {
                dp[i][j]=INT_MAX;
                for(int x=1;x<=i;x++)
                {
                	// we need to find minimise number of trials
                	
                    dp[i][j]=min(dp[i][j],1+max(dp[x-1][j-1],dp[i-x][j]));// here we have used maximum because we are
                    //taking care of worst case.
                }
            }
        }
        return dp[f][egg];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends

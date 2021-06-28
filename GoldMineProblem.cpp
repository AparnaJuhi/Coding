// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int dp[n+2][m];
        for(int i=0;i<m;i++)
        {
            dp[0][i]=0;
            dp[n+1][i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=M[i-1][0];
        }
        
         for(int j=1;j<m;j++)
        {
           for(int i=1;i<=n;i++)
            {
                int k=max(dp[i][j-1] , max(dp[i-1][j-1], dp[i+1][j-1]));
                dp[i][j]=M[i-1][j]+k;
                //cout<<dp[i][j]<<" ";
            }
        }
        int ans=-1;
         for(int i=1;i<=n;i++)
        {
            ans=max(dp[i][m-1],ans);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends

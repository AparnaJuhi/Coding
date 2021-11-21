//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>&arr ,int N) {
        //Write your code here
        int dp[N+1];
         dp[0]=0;
        dp[1]=0;
        
        
        
        for(int i=2;i<=arr.size();i++)
        {
            dp[i]=min(dp[i-1]+ arr[i-1], dp[i-2]+ arr[i-2]);
            
        }
        return dp[N];
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends

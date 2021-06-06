// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // code here
        //trying to do by memoization
        if(n==r)
        return 1;
        if(n<r)
        return 0;
        long long int mat[n+1][r+1];
        for(int i=1;i<=n;i++)
        {
            mat[i][1]=i;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=2;j<=r;j++)
            {
                if(i<j)
                {
                    mat[i][j]=0;
                }
                else
                {
                    mat[i][j]=(mat[i-1][j-1]+mat[i-1][j])%1000000007;
                }
            }
        }
        
        return mat[n][r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends

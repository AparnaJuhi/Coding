// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>>m)
    {
        // code here
        
        int mat[N+1][N+2];
        for(int i=0;i<=N;i++)
        {
             for(int j=0;j<=N+1;j++)
             {
                 if(i==0 || j==0 || j==N+1)
                 {
                     mat[i][j]=0;
                 }
             }
        }
        
        int ans=0;
        
         for(int i=1;i<=N;i++)
        {
             for(int j=1;j<=N;j++)
             {
                 mat[i][j]=m[i-1][j-1]+max(mat[i-1][j-1], max(mat[i-1][j], mat[i-1][j+1]));
                ans=max(ans, mat[i][j]); 
                 
             }
        }
        
         
       
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends

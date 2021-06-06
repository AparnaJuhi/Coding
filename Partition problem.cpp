// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
      
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        if(sum%2!=0)
        return false;
        sum=sum/2;
        int mat[sum+1][n+1];
        //make a matrix of sumxn
        for(int i=1;i<=sum;i++)
        {
            mat[i][0]=0;
        }
        for(int j=0;j<=n;j++)
        mat[0][j]=1;
        for(int i=1;i<=sum;i++)
        {
            for(int j=1;j<=n;j++)
            {
                mat[i][j]=mat[i][j-1];
                if(i>=arr[j-1])
                {
                    //if sum greater than number
                      mat[i][j]=(mat[i][j] || mat[i-arr[j-1]][j-1]);
                    
                }
            }
        }
        return mat[sum][n];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends

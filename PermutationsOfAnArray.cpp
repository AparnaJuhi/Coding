//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   void fun(vector<vector<int>>&ans, vector<int> a ,int n, int i)
   {
       if(i==n)
       {
           ans.push_back(a);
           return;
       }
       else{
           for(int j=i;j<n;j++)
           {
               swap(a[j],a[i]);
               fun(ans,a,n,i+1);
               swap(a[j],a[i]);
           }
       }
       
   }
    vector<vector<int>> allPerms(vector<int> arr ,int n) {
        vector<vector<int>>ans;
        fun(ans, arr, n, 0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.allPerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends

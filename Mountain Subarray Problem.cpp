#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


class Solution{
  public:
  bool mountain(int a[], int s, int e)
  {
      int flag2=0;
      for(int i=s+1;i<=e;i++)
      {
          if(a[i-1]<=a[i] && flag2==0)
          continue;
          else if(a[i-1]>=a[i])
          {
              flag2=1;
              continue;
          }
          else
          return false;
      }
      return true;
  }
    vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries, int q) {
        vector<bool>ans;
        for(int k=0;k<q;k++)
        {
            int start=queries[k].first;
            int end=queries[k].second;
            if(mountain(a,start,end))
            ans.push_back(true);
            else
            ans.push_back(false);
            
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, i, q;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (i = 0; i < q; i++) {
            cin >> queries[i].first >> queries[i].second;
        }
        Solution obj;
        auto v = obj.processQueries(a, n, queries, q);
        for (bool u : v) {
            cout << (u ? "Yes\n" : "No\n");
        }
    }
    return 0;
}  // } Driver Code Ends

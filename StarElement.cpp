
#include <bits/stdc++.h>

using namespace std;

vector<int> getStarAndSuperStar(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<int> ans = getStarAndSuperStar(arr, n);
        for (int i=1;i<ans.size();i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        cout << ans[0] << "\n";
    }
    return 0;
}
// } Driver Code Ends



vector<int> getStarAndSuperStar(int arr[], int n) {
  int suffix[n];
  suffix[n-1]=arr[n-1];
  for(int i=(n-2);i>=0;i--)
  {
      suffix[i]=max(arr[i],suffix[i+1]);
  }
 

  vector<int>ans;
  
  
   int prefix[n];
  prefix[0]=arr[0];
  for(int i=1;i<n;i++)
  {
      prefix[i]=max(arr[i],prefix[i-1]);
  }
  int count=0;
  if(suffix[0]==prefix[n-1])
  {
       for(int i=0;i<n;i++)
  {
      if(arr[i]==suffix[0])
      count++;
  }
  if(count==1)
  {
      ans.push_back(suffix[0]);
  }
  else
  ans.push_back(-1);
  }
  else
  ans.push_back(-1);
  ans.push_back(suffix[0]);
  for(int i=1;i<n;i++)
  {
      if(suffix[i]!=suffix[i-1])
      ans.push_back(suffix[i]);
  }
  return ans;
}

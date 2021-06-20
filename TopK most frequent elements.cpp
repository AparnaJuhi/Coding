#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  static bool comp(pair<int,int>a, pair<int,int>b)
  {
      if(a.second>b.second)
      return true;
      else if(a.second<b.second)
      return false;
      else
      {
          if(a.first>b.first)
          return true;
          else
          return false;
      }
  }
    vector<int> topK(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
                mp[nums[i]]=1;
            }
            else
            mp[nums[i]]+=1;
        }
        map<int,int>::iterator it;
        vector<pair<int,int>>vec;
        for(it=mp.begin();it!=mp.end();++it)
        {
            vec.push_back(make_pair(it->first,it->second));
        }
        sort(vec.begin(),vec.end(),comp);
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(vec[i].first);
        }
        return ans;
        
        
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends

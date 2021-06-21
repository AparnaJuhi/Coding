#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        //if the sum of numbers of array is not divisible by k, return false
        if(nums.size()%2!=0)
        return false;
        
        //make a hash map for remainders
        map<int,int>mp;
        for(int i=0;i<k;i++)
        {
            mp[i]=0;
        }
        
        int temp=0;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]%k]++;
        }
        
        //number of elements completely divisible by k should be even
        if(mp[0]%2!=0)
        return false;
        for(int i=1;i<k;i++)
        {
            if(mp[i]!=mp[k-i])
            return false;
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends

class Solution {
public:
     void fun(set<vector<int>>&ans, vector<int> a ,int n, int i)
   {
       if(i==n)
       {
           ans.insert(a);
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
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>s;
        fun(s, nums, nums.size(), 0);
        vector<vector<int>>v;
        set<vector<int>>:: iterator it;
        for(it=s.begin(); it!=s.end(); it++)
        {
            v.push_back(*it);
        }
        return v;
        
        
    }
};

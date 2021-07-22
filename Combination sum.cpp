class Solution {
public:
    void fun( set<vector<int>> &ans, vector<int>t,  vector<int>c, int ta, int sum)
    {
        if(sum==ta)
        {
            sort(t.begin(),t.end());
            ans.insert(t);
            
            return;
        }
        else if(sum>ta)
            return;
        for(int i=0;i<c.size();i++)
        {
           
           
           t.push_back(c[i]);
            fun(ans, t, c, ta, sum+c[i]);
           t.pop_back();
            //sum-=c[i];
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         set<vector<int>> ans;
         vector<int>p;
         int sum=0;
        //by backtracking
         fun(ans, p, candidates, target, sum);
        vector<vector<int>>res;
         set<vector<int>>:: iterator it;
        for(it=ans.begin();it!=ans.end();++it)
            res.push_back(*it);
        
        return res;
    }
};

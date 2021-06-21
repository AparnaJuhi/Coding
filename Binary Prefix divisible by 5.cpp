class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>ans;
        unsigned long long int k=0;
        
        for(int i=0;i<nums.size();i++)
        {
        
            k=k*2 + nums[i];
            k=k%5;
            if(k==0)
                ans.push_back(true);
            else
                ans.push_back(false);
            
            
        }
        return ans;
    }
};

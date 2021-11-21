class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        //check whether sum is highest alone or with addtion
        int ans=0;
        int ans1=99999;int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=max(nums[i], sum+nums[i]); ans=max(ans,sum);
                
        }sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=min(nums[i], sum+nums[i]);
           
            ans1=min(ans1,sum);
            
                
        }
        return max(abs(ans1), abs(ans));
        
    }
};

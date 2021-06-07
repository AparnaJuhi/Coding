class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        sort(nums.begin(),nums.end());
        int count=1;
        int maxi=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]+1 == nums[i])
            {
                count++;
                maxi=max(maxi,count);
            }
            else if(nums[i-1]==nums[i])
                continue;

            else
            {
                count=1;
            }
        }
        return maxi;
        
    }
};

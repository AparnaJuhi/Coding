class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size()-2;i++)
        {
            int r=nums.size()-1;
            int l=i+1;
            while(l<r)
            {
                int lower=lower_bound(nums.begin(), nums.end(), nums[i]+nums[l]) - nums.begin();
                if(lower>l)
                count+=((lower-1)-l);
                l++;
            }
        }
        return count;
        
    }
};

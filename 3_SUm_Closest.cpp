class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res=INT_MAX;int sol;
        for(int i=0; i<nums.size()-2;i++)
        {
            int sum=nums[i];
            int l=i+1;
            int r=nums.size()-1;
            
            while(l<r)
            {
                int ans=sum+nums[l]+nums[r];
                if(res > abs(target-ans))
                {
                    res=abs(target-ans);
                    sol=ans;
                }
                if(ans > target)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return sol;
    }
};

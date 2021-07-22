class Solution {
public:
    int lower(vector<int>nums, int t)
    {
        int l=0;
        int r=nums.size()-1;
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==t)
            {
                ans=mid;
                r=mid-1;
            }
            else if(nums[mid]>t)
            {
                 r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
    int upper(vector<int>nums, int t)
    {
        int l=0;
        int r=nums.size()-1;
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==t)
            {
                ans=mid;
                l=mid+1;
            }
            else if(nums[mid]>t)
            {
                 r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=lower(nums, target);
        int r= upper(nums,target);
        vector<int>ans;
        ans.push_back(l);
        ans.push_back(r);
        return ans;
    }
};

class Solution {
public:
    bool bs(vector<int>nums,int t)
    {
        int l=0;
        int r=nums.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==t)
                return true;
            else if(nums[mid]>t)
            {
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return false;
    }
    int lb(vector<int>nums,int t)
    {
        int l=0;
        int r=nums.size()-1;
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==t)
            {ans=mid;
            r=mid-1;}
            else if(nums[mid]>t)
            {
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
    int ub(vector<int>nums,int t)
    {
        int l=0;
        int r=nums.size()-1;  int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==t)
            {  ans=mid;
             l=mid+1;
            }
            else if(nums[mid]>t)
            {
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        //by lower_bound and upper bound
        
        //firstly check that whether the element is present or not by bs
        vector<int>v;
        if(bs(nums,target))
        {
            int lower,upper;
            lower=lb(nums,target);
            upper=ub(nums,target);
            v.push_back(lower);
            v.push_back(upper);
            return v;
            
        }
        else
        {
            v.push_back(-1);v.push_back(-1);return v;
        }
    }
};

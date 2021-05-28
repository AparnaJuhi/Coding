class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int maxi=-99999;
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            mp[nums[i]]=1;
            maxi=max(maxi,nums[i]);
        }
        if(maxi<=0)
            return 1;
        else
        {
            map<int,int>::iterator it;
            for(int i=1;i<=maxi;i++)
            {
                if(mp.find(i)==mp.end())
                    return i;
            }
            return maxi+1;
        }
        
    }
};

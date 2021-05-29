class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int>mp;
        int start=-1;
        int sum1=0;
        int sum[nums.size()];
        for(int i=0;i<nums.size();i++)
        {
            sum1+=nums[i];
            sum[i]=sum1;
           // cout<<sum1<<" ";
        }
        //cout<<"\n";
        int total=0;
        int maxi=-9999;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
                mp[nums[i]]=i;
                if(start>=0)
                total=sum[i]-sum[start];
                else
                    total=sum[i];
            }
            else
            {
               start=max(mp[nums[i]],start);
                total=sum[i]-sum[start];
                mp[nums[i]]=i;
                
            }
            
            //cout<<total<<"\n";
            maxi=max(maxi,total);
            
        }
        return maxi;
        
    }
};

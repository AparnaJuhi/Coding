class Solution {
public:
    bool fun(vector<int>w, int days, int ans)
    {
        int req=1;
        int sum=0;
        for(int i=0;i<w.size();i++)
        {
            if(sum+w[i] > ans)
            {
                sum=w[i];
                req+=1;
            }
            else
                sum+=w[i];
        }
        if(req<=days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        //a binary search question
        int n=weights.size();
        if(n==1)
            return weights[0];
        int sum=0,maxi=INT_MIN;
        for(int i=0; i<n;i++)
        {
            sum+=weights[i];
            maxi=max(maxi,weights[i]);
        }
        int low=maxi;
        int high=sum;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(fun(weights,days,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans; }
};

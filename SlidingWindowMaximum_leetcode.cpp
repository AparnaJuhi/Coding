class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        for(int i=0;i<k;i++)
        {
            if(dq.empty())
            dq.push_back(i);
            else
            {
                int t=dq.front();
                
                    while(!dq.empty() && nums[dq.back()]<nums[i])
                    dq.pop_back();
                    dq.push_back(i);
                
            }
        }
        vector<int>ans;
        ans.push_back(nums[dq.front()]);
        
        for(int i=k;i<n;i++)
        {
            if(dq.empty())
            {
                dq.push_back(i);
                ans.push_back(nums[i]);
            }
            else
            {
                while(!dq.empty() && nums[dq.back()]<nums[i])
                {
                    dq.pop_back();
                }
                
                dq.push_back(i);
                if(dq.front()<=i-k)
                    dq.pop_front();
                ans.push_back(nums[dq.front()]);
                
            }
        }
        return ans;
        
        
        
    }
};

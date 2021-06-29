class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int window=0;
        int count0=0;
        int start=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[0]==0)
                count0++;
            if(count0<=k)
            {
                window=max(window, i-start+1);
            }
            else
            {
                if(nums[start]==0)
                    count0--;
                start++;
            }
        }
        return window;
        
    }
};

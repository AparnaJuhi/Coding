class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        //it is similar to LIS
        sort(nums.begin(),nums.end());
        
        // just sort it because sequence does not matter
        int n=nums.size();
        int count=0;
        vector<int>list[n];
        list[0].push_back(nums[0]);
       
        vector<int>ans;
       int maxi=0;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
               if(nums[i]%nums[j]==0)
               { 
                 //now check each of their list
                   if(list[i].size()<list[j].size())
                   {
                       list[i].clear();
                       
                       //overrwrite list[i] with list[j]
                       list[i].insert(list[i].end(),list[j].begin(),list[j].end());
                   }
               }
               
            }
            list[i].push_back(nums[i]);
            
        }
        int ansIdx=0;
        for(int i=0;i<n;i++)
        {
            if(list[i].size()>maxi)
            {
                maxi=list[i].size();
                ansIdx=i;
            }
        }
        return list[ansIdx];
    }
};

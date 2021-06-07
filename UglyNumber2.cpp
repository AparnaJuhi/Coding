class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp;
        dp.push_back(1);
        int k=0,l=0,m=0;
        while(dp.size()<n)
        {
            if(dp[k]*2 <=dp[l]*3  &&  dp[k]*2 <=dp[m]*5)
            {
                dp.push_back(dp[k]*2);
                
                if(dp[k]*2 == dp[l]*3)
                {
                    l++;
                }
                if(dp[k]*2 == dp[m]*5)
                {
                    m++;
                }
                k++;
            }
            
            else if(dp[l]*3 <=dp[k]*2  &&  dp[l]*3 <=dp[m]*5)
            {
                dp.push_back(dp[l]*3); 
                if(dp[k]*2 == dp[l]*3)
                {
                    k++;
                }
                if(dp[l]*3 == dp[m]*5)
                {
                    m++;
                }
                l++;
            }
            
            else 
            {
                dp.push_back(dp[m]*5); 
                if(dp[k]*2 == dp[m]*5)
                {
                    k++;
                }
                if(dp[l]*3 == dp[m]*5)
                {
                    l++;
                }
                m++;
            }
        }
        return dp[n-1];
    }
};

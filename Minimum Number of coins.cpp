class Solution{
public:
    vector<int> minPartition(int sum)
    {
    
       vector<int>ans[sum+1];
        int dp[sum+1];
        int coins[10];
        coins[0]=1; coins[1]=2;
         coins[2]=5;  coins[3]=10;
          coins[4]=20; coins[5]=50;
           coins[6]=100; coins[7]=200;
            coins[8]=500; coins[9]=2000;
        int k=0;
         for(int i=0;i<=sum;i++)
         {
             if(coins[k]==i)
             {
                 k++;
                 dp[i]=1;
                 ans[i].push_back(i);
             }
             else
             dp[i]=INT_MAX;
         }
         
        
     
        for(int i=1;i<=sum;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(coins[j] < i)
                {
                    if(dp[i-j]!=INT_MAX)
                    {   
                        if(dp[i]>dp[i-coins[j]]+dp[coins[j]])
                        {
                          dp[i]=dp[i-coins[j]]+dp[coins[j]];
                          ans[i].clear();
                          ans[i].insert(ans[i].end(),ans[i-coins[j]].begin(), ans[i-coins[j]].end());
                          ans[i].insert(ans[i].end(),ans[coins[j]].begin(), ans[coins[j]].end());
                        }
                        
                    }
                }
            }
        }
        
        if(dp[sum]==INT_MAX)
        {
            vector<int>k;
            k.push_back(-1);
            return k;
        }
        else
        {
            sort(ans[sum].rbegin(),ans[sum].rend());
            return ans[sum];
        }
    }
};

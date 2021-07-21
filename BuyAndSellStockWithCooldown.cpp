class Solution {
public:
    int fun(vector<int> prices, int &maxi, int i,int sum, int price_carried, int flag)
    {
        if(i==prices.size())
        {
            maxi=max(sum,maxi);
            return maxi;
        }
        
        if(flag==0)
        {
            //we can buy
            fun(prices, maxi, i+1, sum, -prices[i], 1);
            
            //if we leave
            fun(prices, maxi, i+1, sum, 0, 0 );
            
        }
        
        if(flag==1)
        {
            //we can sell 
            fun(prices, maxi, i+1, sum+(prices[i]+price_carried) , 0 ,  2);
            
            // we dont sell
            fun(prices, maxi, i+1,sum,price_carried,1);
        }
        
        if(flag==2)
        {
            //cooldown
            fun(prices, maxi, i+1, sum ,0, 0);
        }
    }
    int maxProfit(vector<int>& prices) {
        int maxi=0,sum=0;
        int i=0;int price_carried=0;
        int dp[prices.size()][3];
        fun(prices, maxi, i,sum,price_carried,0);
        return maxi;
        
    }
};

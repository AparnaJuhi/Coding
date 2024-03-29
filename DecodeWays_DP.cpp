class Solution {
public:
    
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        
        vector<int>dp;
        int n=s.size();
        for(int i=0;i<n;i++)
           dp.push_back(0);
       dp.push_back(1);
        if(s[n-1]!='0')
            dp[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
              if(s[i]!='0'){  
                dp[i]+=dp[i+1];
                 
                }
            if(s[i]=='1' ){
                dp[i]+=dp[i+2];
               
                }
            if(s[i]=='2' ){
                if(s[i+1]<='6'){
                    dp[i]+=dp[i+2];
                }

            }
        }
        return dp[0];
    }
};

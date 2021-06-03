class Solution {
public:
    int dp[1001][1001];
    int fun(string s1, string s2, string s3, int n, int m, int k ) {
        
        //if we have traversed string s3
        
        //cout<<n<<" "<<m<<" "<<k<<"\n";
        if(k==0)
            return true;
        
        else if(dp[n][m]!=-1)
            return dp[n][m];
        
        else
        {
            int a=0,b=0;
           if((n-1>=0) &&s1[n-1]==s3[k-1])
           {
               a=fun(s1, s2, s3, n-1, m , k-1);
           }
            if((m-1>=0) && s2[m-1]==s3[k-1])
           {
               b=fun(s1, s2, s3, n, m-1 , k-1);
           }
            if(a==1 || b==1)
            dp[n][m]=1;
            else
                dp[n][m]=0;
            return dp[n][m];
            
        }
        
    }
    
    
    bool isInterleave(string s1, string s2, string s3)
    {
        if((s1.size() + s2.size())!=s3.size())
        return false;
        
        //solve by memoization
        dp[s1.size()+1][s2.size()+1];
        memset(dp,-1,sizeof(dp));
        
         if(fun(s1 , s2, s3, s1.size(), s2.size() , s3.size()))
            return true;
        else
            return false;
    }
};

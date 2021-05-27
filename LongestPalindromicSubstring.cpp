#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        if(s.size()==0)
        {
            string ans="";
            ans+=s[0];
            return ans;
        }
        else if(s.size()==2)
        {
            if(s[0]==s[1])
                return s;
            else
            {
            string ans="";
            ans+=s[0];
            return ans;
            }
        }
        
        //variables to initialise start and end of palindromic substring
        int start=0;
        int end=0;
         //first of all make a matrix and fill its diagonal elements to 1.
        int n=s.size();
        int dp[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               
                if(i==j)
                dp[i][j]=1;
                else
                    dp[i][j]=0;//filled all non diagonal elements with zero for now
            }
           
        }
        
        //now filling the upper triangular elements just above diagonals
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j-i==1)
                {
                    if(s[j]==s[i])
                    {
                        dp[i][j]=1;
                        if((j-i)>(end-start))
                        {
                            end=j;
                            start=i;
                        }
                    }
                }
            }
        }
        
        // now fill all other elements diagonally
        
        int k=2;
        
     
        int i=0;
        while(1)
        {
            int original=i;
            for(int j=k;j<n;j++)
            {
                
                dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                if(dp[i][j]==1)
                {
                    if((j-i)>(end-start))
                    {
                        end=j;
                        start=i;
                    }
                }
                i++;
            }
           i=original;
            k++;
            if(k>=n)
                break;
            
        }
      
        string ans="";
        for(int i=start;i<=end;i++)
            ans+=s[i];
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}

  // } Driver Code Ends

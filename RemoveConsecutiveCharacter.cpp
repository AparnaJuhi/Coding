#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        stack<char>st;
        for(int i=0;i<S.size();i++)
        {
            if(st.empty())
            st.push(S[i]);
            else
            {
                if(st.top()!=S[i])
                st.push(S[i]);
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 



  // } Driver Code Ends

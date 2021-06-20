// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string s){
        // code here
        stack<int>st;
        int maxi=0;
        st.push(-1);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                if(!st.empty())
                st.pop();
                if(!st.empty())
                {
                    maxi=max(maxi,i-st.top());
                }
                else
                {
                    st.push(i);
                }
            }
        }
        return maxi;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends

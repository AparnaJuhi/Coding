//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isPalindrome(string s)
    {
        int n=s.size();
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=s[n-i-1])
            return false;
        }
        return true;
    }
    string longestPalindrome(string S){
        string ans="";
        for(int i=0;i<S.size();i++)
        {
            
            string k="";
            for(int j=i;j<S.size();j++)
            {
                k+=S[j];
                if(isPalindrome(k) && k.size()>ans.size())
                ans=k;
            }
            
        }
        return ans;
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
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends

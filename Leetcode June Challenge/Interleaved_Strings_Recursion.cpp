#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
  public:

    bool fun(string s1, string s2, string s3, int i, int j, int k) {
        
        //check if all strings are empty return true
        if(i==s1.size() && j==s2.size() && k==s3.size())
            return true;
        
        //check if s3 is empty and any of the two strings are not empty
        else if(s3.size()==k)
        {
            return false;
            
        }
        
        else
        {
            return((s1[i]==s3[k]  && fun(s1,s2,s3,i+1,j,k+1) ) || (s2[j]==s3[k]  && fun(s1,s2,s3,i,j+1,k+1))); 
        }
        
    }
    
    
    bool isInterleave(string s1, string s2, string s3)
    {
        if((s1.size() + s2.size())!=s3.size())
        return false;
        if(fun(s1 , s2, s3, 0, 0 , 0))
            return true;
        else
            return false;
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends

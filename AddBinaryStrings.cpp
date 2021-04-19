#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    string ans;
	    while(A.size()<B.size())
	    {
	        A='0'+A;
	    }
	    while(A.size()>B.size())
	    {
	        B='0'+B;
	    }
	    char carry='0';
	    
	    reverse(A.begin(),A.end());
	    reverse(B.begin(),B.end());
	   
	    for(int i=0;i<A.size();i++)
	    {
	        if(A[i]=='0' && B[i]== '0')
	        {
	            ans+=carry;
	            carry='0';
	        }
	        else if((A[i]=='0' && B[i]=='1') ||(A[i]=='1' && B[i]=='0'))
	        {
	            if(carry=='0')
	            {ans+='1';
	            }
	            else
	            {ans+='0';
	            carry='1';}
	        }
	        else
	        {
	            if(A[i]=='1' && B[i]=='1')
	            {
	                if(carry=='1')
	                {
	                    ans+='1';
	                }
	                else
	                {
	                    ans+='0';
	                    carry='1';
	                }
	            }
	        }
	    }
	    if(carry=='1')
	    ans+=carry;
	    reverse(ans.begin(),ans.end());
	    while(ans[0]=='0')
	    {
	        ans.erase (ans.begin(), ans.begin()+1);
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}


 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	string findSum(string A, string B) 
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
	    int carry=0;
	    
	    reverse(A.begin(),A.end());
	    reverse(B.begin(),B.end());
	   
	    for(int i=0;i<A.size();i++)
	    {
	       int a=A[i]-'0';
	       int b=B[i]-'0';
	       if((a+b+carry)<=9)
	       {ans+=((a+b+carry)+'0');carry=0;}
	       else
	       {
	           ans+=((a+b+carry)%10)+'0';
	           carry=1;
	       }
	    }
	    if(carry==1)
	    ans+=(carry+'0');
	    reverse(ans.begin(),ans.end());
	     while(ans[0]=='0' && ans.size()>1)
	    {
	        ans.erase (ans.begin(), ans.begin()+1);
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string x, y;
   		cin >> x >> y;
        Solution ob;
   		cout << ob.findSum(x, y) << "\n";
   	}

    return 0;
}  // } Driver Code Ends

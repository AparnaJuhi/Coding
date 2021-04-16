#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{   
public:
    char decodeIt(string str, int k)
    {int n=str.size();
    string ans="";
       for(int i=0;i<n;i++)
       {
           if(str[i]>='0' && str[i]<='9')
           {
               int times=str[i]-'0';
               string p=ans;
               for(int j=1;j<times;j++)
               ans+=p;
           }
           else
           ans+=str[i];
       }
       return ans[k-1];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        int k;
        cin>>k;
        Solution ob;
        cout << ob.decodeIt(str,k) << endl;
    }
}  // } Driver Code Ends

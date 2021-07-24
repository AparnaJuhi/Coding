// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int convertEvenBitToZero(long long int n) {
       string binary="";
       while(n>0)
       {
           int k=n%2;
           if(k%2==0)
           {
               binary=binary+"0";
           }
           else
           {
               binary=binary+"1";
           }
           n=n/2;
       }
       
       long long int ans=0;
       
       for(int i=0;i<binary.size();i++)
       {
           if(i%2==0)
           {
               binary[i]='0';
           }
       }
       //cout<<binary<<"\n";
       int p=1;
       for(int i=0;i<binary.size();i++)
       {
           if(binary[i]=='1')
           {
               ans+=p;
           }
           p=p*2;
       }
       return ans;
       
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.convertEvenBitToZero(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends

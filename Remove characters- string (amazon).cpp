// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string removeChars(string s1, string s2) {
        char arr[256];
        
        for(int i=0;i<256;i++)
        {
           arr[i]=0; 
        }
        for(int i=0;i<s2.size();i++)
        {
           arr[s2[i]]++; 
        }
        string ans="";
        for(int i=0;i<s1.size();i++)
        {
           if(arr[s1[i]]==0)
           {
               ans+=s1[i];
           }
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string string1,string2;
        cin >> string1; 
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1,string2) << endl;
    }
    return 0;
}
  // } Driver Code Ends

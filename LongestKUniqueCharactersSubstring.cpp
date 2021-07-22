#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    int longestKSubstr(string s, int k) {
     int maxi=-1;
     int arr[26];
     for(int i=0;i<26;i++)
     {
         arr[i]=0;
     }
     int dis=0;
     int start=0;
     for(int i=0;i<s.size();i++)
     {
         if(arr[int(s[i]-97)]==0)
         {
             dis++;
             arr[int(s[i]-97)]=1;
         }
         else
         {
             arr[int(s[i]-97)]+=1;
         }
         if(dis==k)
            {
                //cout<<start<<" "<< i<<"\n";
             maxi=max(maxi, (i- start)+1);
            }
       
        while(dis>k)
        {
            
            arr[int(s[start]-97)]--;
           
            if(arr[int(s[start]-97)] ==0)
            dis--;
             start++;
            
            
        }
       
        
     }return maxi;
     
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends

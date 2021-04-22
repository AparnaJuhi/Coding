#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> printMissingIntervals(int a[], int n) {
        sort(a,a+n);
        vector<int>v;
        if(a[0]!=0)
        {
            v.push_back(0);
            v.push_back(a[0]-1);}
            
            for(int i=0;i<(n-1);i++)
            {
                
                if((a[i+1]-a[i])>1)
                {v.push_back(a[i]+1);
                v.push_back(a[i+1]-1);
                }
            }
            if(a[n-1]!=99999)
            {
                v.push_back(a[n-1]+1);
                v.push_back(99999);
            }
            return v;
        }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        int a[n];
        for(int i=0 ; i<n ; i++)
            cin>>a[i];

        Solution ob;
        vector<int> vec = ob.printMissingIntervals(a,n);
        
        for(int i=0 ; i<vec.size() ; i+=2)
        {
            if (vec[i]==vec[i+1])
                cout<<vec[i];
            else
                cout<<vec[i]<<"-"<<vec[i+1];
            if(i!=vec.size()-2)
                cout<<",";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends

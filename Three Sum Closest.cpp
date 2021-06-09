//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution{
  public:
    int threeSumClosest(vector<int> a, int target) {
        // Your code goes here
        int mini=INT_MAX;
        sort(a.begin(),a.end());
        int n=a.size();
        int ans;
        for(int i=0;i<n-2;i++)
        {
            int l=i+1;
            int r=n-1;
            int sum=a[i];
            while(l<r)
            {
                int k=a[l]+a[r]+sum;
                if(mini>abs(target-k))
                {
                    mini=abs(target-k);
                    ans=k;
                }
                else if(mini==abs(target-k))
                {
                    if(k>ans)
                    ans=k;
                }
                if(k>target)
                {
                    r--;
                }
                else
                {
                    l++;
                }
                
            }
        }
        return ans;
        
    }
};



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        int n,target;
        cin >> n >> target;
        
        vector<int> vec(n);
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}

//Position this line where user code will be pasted.
  // } Driver Code Ends

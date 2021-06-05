#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int bs(int a[],int l, int r,int size)
	{
	    int ans=-1;
	    while(l<=r )
	    {
	        int mid=(l+r)/2;
	        if(a[mid]>a[mid-1])
	        {
	            ans=max(ans,a[mid]);
	            l=mid+1;
	        }
	        else
	        {
	            r=mid-1;
	           ans=max(ans,a[mid]); 
	        }
	        
	    }
	    return ans;
	}
	int findMaximum(int arr[], int n) {
	    if(arr[0]>arr[1])
	    return arr[0];
	    else if(arr[n-1]>arr[n-2])
	    return arr[n-1];
	  return bs(arr,0,n-1,n-1);
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends

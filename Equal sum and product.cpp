#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// returns required number of subarrays
	int numOfsubarrays(int arr[], int n) {
	    int sum[n+1];
	    int pro[n+1];
	    sum[0]=0;
	    pro[0]=1;
	    for(int i=1;i<=n;i++)
	    {
	        sum[i]=sum[i-1]+arr[i-1];
	        pro[i]=pro[i-1]*arr[i-1];
	    }
	    int count=0;
	     for(int i=1;i<=n;i++)
	    {
	         for(int j=0;j<i;j++)
	         {
	             if(pro[i]/pro[j] == sum[i]-sum[j])
	             count+=1;
	         }
	    }
	    return count;
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
        auto ans = ob.numOfsubarrays(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends

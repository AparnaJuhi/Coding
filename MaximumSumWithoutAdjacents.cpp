#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    int excl=0, incl=arr[0];
	    int excl_new;int i=0;
	   for (i = 1; i < n; i++)
        {
           
            if(incl<excl)
            excl_new=excl;
            else
            excl_new=incl;
            incl = excl + arr[i];
            excl = excl_new;
        }
        return max(excl, incl);
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends

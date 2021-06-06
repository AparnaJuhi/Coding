//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long countEvenSum(int arr[], int n) {
        // find prefix sum
        //try to observe pattern
        int pre[n];
        long long count=0;
        int countodd=0;//count number of odd numbers before present number
        int counteven=0;
        //count no of even numbers before this number including this number
        pre[0]=arr[0];
        if(pre[0]%2==0)
        {
            counteven++;
            count+=counteven;
        }
        else
        {
            countodd++;
        }
        for(int i=1;i<n;i++)
        {
            pre[i]=arr[i]+pre[i-1];
            
            //slight diff for odd and even
            
            //if encounter even first increment then count
            //because we have encountered even
            if(pre[i]%2==0)
            {
                counteven++;
                count+=counteven;
            }
            else
            {
                count+=countodd;
                countodd++;
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
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countEvenSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

  // } Driver Code Ends

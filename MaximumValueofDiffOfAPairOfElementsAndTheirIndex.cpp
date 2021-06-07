//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxValue(int a[], int N) {
        // add their index in value of each number
        if(N<2)
        return 0;
        int arr[N];
        int brr[N];
        for(int i=0;i<N;i++)
        {
            arr[i]=a[i]+i;
            brr[i]=a[i]-i;
        }
        
        /*
        arr[i] - arr[j] + i - j = (arr[i] + i) - (arr[j] + j)
        arr[i] - arr[j] - i + j = (arr[i] - i) - (arr[j] - j)
        -arr[i] + arr[j] + i - j = -(arr[i] - i) + (arr[j] - j)
        -arr[i] + arr[j] - i + j = -(arr[i] + i) + (arr[j] + j)
        
        make two arrays- one to store arr[i]+i and other form arr[i]-i
*/
        
        //ans will be the maximum difference of max and min value
        int mini1=INT_MAX;
        int maxi1=0;
        int mini2=INT_MAX;
        int maxi2=0;
        for(int i=0;i<N;i++)
        {
            mini1=min(arr[i],mini1);
            maxi1=max(arr[i],maxi1);
            
            mini2=min(brr[i],mini2);
            maxi2=max(brr[i],maxi2);
        }
        return (max(maxi1-mini1, maxi2-mini2));
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxValue(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends

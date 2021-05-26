//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N) {
    int lastGoodPos=N-1;
    int i;
    for(i=N-1;i>=0;i--)
    {
        if(i+A[i]>=lastGoodPos)
        lastGoodPos=i;
    }
    if(lastGoodPos==0)
    return true;
    return false;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int arr[], int n, int k)
    {
        // code here
        
        //trying by sliding window
        int sum=0;
        int count=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            int second=sum-k;
            if(mp.find(second)!=mp.end())
            count+=mp[second];
            
            if(mp.find(sum)==mp.end())
            {
                mp[sum]=1;
            }
            else
            mp[sum]+=1;
        }
        
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends

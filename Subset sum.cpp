#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void fun(vector<int>&p, vector<int> arr, int N,int i,int sum=0)
    {
       
         if(i>=N)
        {
           p.push_back(sum);
           return;
        }
    fun(p,arr,N,i+1,sum+arr[i]);
     fun(p,arr,N,i+1,sum);
   
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
       
        vector<int>k;
        fun(k,arr,N,0,0);
        sort(k.begin(),k.end());
        return k;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends

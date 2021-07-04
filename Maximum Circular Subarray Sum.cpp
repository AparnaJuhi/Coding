#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int n){
     // do two things
     //find minimum sum subarray
      int res=arr[0];
    int curr=arr[0];
    int sum=arr[0];
    for(int i=1;i<n;i++)
    {
        curr=max(curr+arr[i],arr[i]);
        res=max(curr,res);
        sum+=arr[i];
    }
    if(res<0)
    return res;
    int res1=arr[0];
    int curr1=arr[0];
    for(int i=1;i<n;i++)
    {
        curr1=min(curr1+arr[i],arr[i]);
        res1=min(curr1,res1);
    }
    if(sum-res1 > res)
    return sum-res1;
    else
    return res;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends

//Initial Template for C++

// C++ implementation to rearrange the array 
// elements after modification 
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        void modifyAndRearrangeArr(int arr[], int n) 
    { 
    	for(int i=0;i<n-1;i++)
    	{
    	    if(arr[i]==arr[i+1] && arr[i]!=0)
    	    {
    	        arr[i]=2*arr[i];
    	        arr[i+1]=0;
    	       
    	    }
    	}
    	int count0=0;
    	int brr[n];
    	for(int i=0;i<n;i++)
    	{
    	    brr[i]=arr[i];
    	    if(arr[i]==0)
    	    count0++;
    	    
    	}
    	int j=0;
    	for(int i=0;i<n;i++)
    	{
    	    if(brr[i]!=0)
    	    {
    	        arr[j]=brr[i];j++;
    	    }
    	}
    	for(int i=0;i<count0;i++)
    	{
    	    arr[j]=0;
    	    j++;
    	}
    }
}; 


// { Driver Code Starts.
// Driver program to test above 
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        ob.modifyAndRearrangeArr(arr, n);
        for(int i=0;i<n;i++)
            cout << arr[i] << " ";
        cout << endl;
        
    }

	return 0; 
} 
  // } Driver Code Ends

//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int findMedian(int *, int , int *, int);

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int arr[n];
	    int brr[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> brr[i];
	    }
	    
	    if(n < m)
	        cout << findMedian(arr, n, brr, m) << endl;
	   else
	        cout << findMedian(brr, m, arr, n) << endl;
	    
	}

}// } Driver Code Ends


//User function template for C++

// arr : given array with size n 
// brr : given array with size m
int findMedian(int arr[], int n, int brr[], int m){
    int median=(n+m)/2;
    if((n+m)%2!=0){
    int count=0;int i=0,j=0;
    int ans;
    while(count<=median && i<n &&j<m)
    {
        if(arr[i]<brr[j])
        {
            ans=arr[i];
            count++;i++;
        }
        else
        {
           ans=brr[j];
            count++; j++;
        }
    }
    
     while(count<=median && i<n)
     {
          ans=arr[i];
            count++;i++;
     }
     
     while(count<=median && j<m)
     {
         ans=brr[j];
            count++; j++; 
     }
     return ans;
    
    }
    else
    {
        //it means we need to output the avg of two
         int count=0;int i=0,j=0;
    int ans1=0,ans2=0;
    while(count<=median && i<n &&j<m)
    {
        if(arr[i]<brr[j])
        {
            ans1=ans2;
            ans2=arr[i];
            count++;i++;
        }
        else
        {
            ans1=ans2;
            ans2=brr[j];
            count++; j++;
        }
    }
    
     while(count<=median && i<n)
     {
            ans1=ans2;
            ans2=arr[i];
            count++;i++;
     }
     
     while(count<=median && j<m)
     {
            ans1=ans2;
            ans2=brr[j];
            count++; j++; 
     }
     return((ans1+ans2)/2);
    }

}

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int count=0;
        int i=0,j=0;
        int ans;
        while(count!=k && i<n && j<m)
        {
            if(arr1[i]<arr2[j])
            {
                ans=arr1[i];i++;
            }
            else
            {
                  ans=arr2[j];j++;
            }
            count++;
        }
         while(count!=k && i<n)
         {
             ans=arr1[i];i++;  count++;
         }
         while(count!=k && j<m)
         {
             ans=arr2[j];j++;  count++;
         }
         return ans;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code 
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
	int bs(long long int l,long long int r,long long int n,double res)
	{
	    int ans=-1;
	    while(l<=r)
	    {
	        int mid=(l+r)/2;
	       // cout<<mid<<" ";
	        double t=pow(mid,n);
	        //cout<<t<<"\n";
	        
	        if(t==res)
	        return mid;
	        else if(t<res)
	        {l=mid+1;
	           }
	        else
	        r=mid-1;
	        
	    }
	    return ans;
	}
	int NthRoot(int n, int m)
	{
	    if(m==1 || n==1)
	    return m;
	    return bs(1,m,n,m);
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends

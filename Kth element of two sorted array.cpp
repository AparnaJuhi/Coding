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
}  // } Driver Code Ends

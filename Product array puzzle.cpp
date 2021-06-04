//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& a, int n) {
       
        long long int k=0;
        long long int count0=0,product=1;
        vector<long long int> ans;
        for(k=0;k<n;k++)
        {
            if(a[k]==0)
            {
                count0++;
            }
            else
            {
                product=product*a[k];
            }
            
        }
        for(k=0;k<n;k++)
        {
            if(a[k]!=0 && count0>0)
            {
                ans.push_back(0);
            }
            else if(a[k]!=0)
            {
                ans.push_back(product/a[k]);
            }
            else
            {
                if(a[k]==0 && count0==1)
                {
                    ans.push_back(product);
                }
                else
                {
                     ans.push_back(0);
                }
            }
        }
        
        
        return ans;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends

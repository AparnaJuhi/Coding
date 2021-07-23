#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        int sum1=0,sum2=0;
        set<int>s1,s2;
        for(int i=0;i<n;i++)
        {
            sum1+=A[i];
            s1.insert(A[i]);
        }
        
        for(int i=0;i<m;i++)
        {
            sum2+=B[i];
            s2.insert(B[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            int a1=sum1-A[i];
            int b1=sum2+A[i];
            //A lost the value and B gained it
            //now check whether the diff can be compensate by B
            
            //my observation
            int diff=b1-a1;
            if(diff%2==0)
            {if(s2.find(diff/2)!=s2.end())
            return 1;
            }
        }
        return -1;
	}
 

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends

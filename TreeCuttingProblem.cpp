#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    long long bs(int tree[],int low,int high,int x,int n){
    long long ans=-1;
    long long total_wood=0;
    for(int i=0;i<n;i++)
    total_wood+=tree[i];
           while(low<=high)
           {
               long long mid=(low+high)/2;
               //cout<<mid<<"  ";
               long long wood_cut=0;
               for(int i=0;i<n;i++)
               {
                   if(mid<tree[i])
                   wood_cut=wood_cut+(tree[i]-mid);
               }
              // cout<<wood_cut<<"\n";
               if(wood_cut==x)
               {
                   return mid;
               }
               else if(wood_cut>x)
               {
                  low=mid+1;
               }
               else
               high=mid-1;
           }
           return ans;
    }
    int find_height(int tree[], int n, int k)
    {
        //find maximum height of tree
        sort(tree,tree+n);
        return bs(tree,1,tree[n-1],k,n);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}  // } Driver Code Ends

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{

public:
    int mindistinct(int a[], int n, int k)
    {
        map<int,int>mp;
        for(int i=0;i<n;i++)
	    {
	      if(mp.find(a[i])==mp.end())
	      {
	          mp[a[i]]=1;
	      }
	      else
	      mp[a[i]]++;
	    }
	    map<int,int>::iterator it;
	    vector<pair<int,int>>v;
	    for(it=mp.begin();it!=mp.end();it++)
	    {
	        int a=it->first;
	        int b=it->second;
	        v.push_back(make_pair(b,a));
	    }
	    
	    sort(v.begin(),v.end());
	    int idx=0;
	    int count=0;//to count number of elements deleted
	    
	    while(count<k)
	    {
	        v[idx].first-=1;
	        count++;
	        if(v[idx].first==0)
	        {
	            idx++;
	        }
	    }
	    //cout<<idx<<"\n";
	    return v.size()-idx;
	    
	  
	  
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        cin>>k;
        
        Solution ob;
        int ans = ob.mindistinct(arr,n,k);
        cout << ans << endl;
    }
    return 0;
}
  // } Driver Code Ends

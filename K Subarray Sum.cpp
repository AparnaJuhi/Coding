#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,m,k;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m>>k;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	    int sum=0;
	    vector<int>v;
	    for(int j=0;j<m;j++)
	    sum+=arr[j];
	    v.push_back(sum);
	    int kk=0;
	    for(int j=m;j<n;j++)
	    {
	        sum-=arr[kk];
	        kk++;
	        sum+=arr[j];
	        v.push_back(sum);
	    }
	    sort(v.begin(),v.end());
	    reverse(v.begin(),v.end());
	    for(int i=0;i<k;i++)
	    {
	        cout<<v[i]<<" ";
	    }cout<<"\n";
	}
	return 0;
}

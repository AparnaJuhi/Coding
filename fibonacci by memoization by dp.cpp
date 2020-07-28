#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ull unsigned long long
ull FB(ull int n,vector<long>&dp)
{
	if(n==0)
	return 0;
	else if(n==1||n==2)
	return 1;
	else
	return dp[n]=(FB(n-1,dp)+FB(n-2,dp))%1000000007;
}
int main() {
    long long int t,n,ans;
	cin>>t;
	while(t--)
	{
	    
	    cin>>n;
	    vector<long>dp(n+1,-1);
	    ans=FB(n,dp)%1000000007;
	    cout<<ans<<"\n";
	    
	}
}

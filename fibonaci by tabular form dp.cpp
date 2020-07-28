#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ull unsigned long long
int main() {
    long long int t,n,ans;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    vector<long>dp(n+1);
	    dp[1]=1;
	    dp[2]=1;
	    for(int i=3;i<=n;i++)
	    {
	        dp[i]=(dp[i-1]+dp[i-2])%mod;
	    }
	    cout<<dp[n]%mod<<"\n";
	    
	}
}

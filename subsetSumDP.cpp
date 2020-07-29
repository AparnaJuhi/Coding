#include <iostream>
using namespace std;
bool issubset(int n,int set[],int sum)
{
    bool subset[n+1][sum+1];
    //if sum=0, return true
    for(int i=0;i<=n;i++)
    subset[i][0]=true;
    //if n=0 and we have sum remaining, return false
    for(int i=1;i<=sum;i++)
    subset[0][i]=false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<set[i-1])//ignore
            subset[i][j]=subset[i-1][j];
            if(j>=set[i-1])
            {
                subset[i][j]=(subset[i-1][j] || subset[i-1][j-set[i-1]]);
            }
        }
    }
    return subset[n][sum];
    
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int set[n];
	    int add=0,sum;
	    for(int i=0;i<n;i++)
	    {
	        cin>>set[i];
	        add=add+set[i];
	    }
	    if(add%2!=0)
	    cout<<"NO\n";
	    else
	    {   
	        int sum=add/2;
	        bool ans=issubset(n,set,sum);
	        if(ans==1)
	        cout<<"YES\n";
	        else
	        cout<<"NO\n";
	   }
	    
	}
}

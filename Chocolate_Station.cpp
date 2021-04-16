
#include <bits/stdc++.h>
using namespace std;
int getChocolateCost(vector<int> arr, int chocolateMrp);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n, tmp;
	    cin>>n;
	    vector<int> arr;
	    while(n--)
	    {
	        cin>>tmp;
	        arr.push_back(tmp);
	    }
	    cin>>tmp;
	    cout<<getChocolateCost(arr, tmp)<<"\n";
	}
	return 0;
}// } Driver Code Ends



int getChocolateCost(vector<int> arr, int mrp)
{
    int bought=arr[0];
    int balance=0;
    int n=arr.size();
    for(int i=1;i<n;i++)
    {
        int k=arr[i-1]-arr[i];
        balance+=k;
        //cout<<balance<<"\n";
        if(balance<0)
        {bought+=abs(balance);
       // cout<<"bought = "<<bought<<"\n";
        balance=0;}
    }
    return (bought*mrp);
}

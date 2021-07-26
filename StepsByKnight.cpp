#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool vis[1001][1001];
    bool valid(int i, int j, int n)
    {
        if(i>0 && i<=n && j>0 && j<=n && vis[i][j]==false)
        {
            return true;
        }
        return false;
    }
	int minStepToReachTarget(vector<int>&k,vector<int>&t,int n)
	{
	    //bfs
	    int b[n+1][n+1];
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=n;j++)
	        vis[i][j]=false;
	    }
	    vis[k[0]][k[1]]=true;
	    queue<pair<int,int>>q;
	    b[k[0]][k[1]]=0;
	    q.push(make_pair(k[0],k[1]));
	    while(!q.empty())
	    {
	        pair<int,int>pa=q.front();
	        q.pop();
	        int i=pa.first;
	        int j=pa.second;
	        if(valid(i+2,j+1,n))
	        {
	            b[i+2][j+1]=1+b[i][j];
	            vis[i+2][j+1]=true;
	            q.push(make_pair(i+2, j+1));
	        }
	        if(valid(i+2,j-1,n))
	        {
	            b[i+2][j-1]=1+b[i][j];vis[i+2][j-1]=true;
	            q.push(make_pair(i+2, j-1));
	        }
	        if(valid(i-2,j+1,n))
	        {
	            b[i-2][j+1]=1+b[i][j];vis[i-2][j+1]=true;
	            q.push(make_pair(i-2, j+1));
	        }
	        if(valid(i-2,j-1,n))
	        {
	            b[i-2][j-1]=1+b[i][j];vis[i-2][j-1]=true;
	            q.push(make_pair(i-2, j-1));
	        }
	        
	        
	        if(valid(i+1,j+2,n))
	        {
	            b[i+1][j+2]=1+b[i][j];vis[i+1][j+2]=true;
	           q.push(make_pair(i+1, j+2));
	        }
	        if(valid(i+1,j-2,n))
	        {
	            b[i+1][j-2]=1+b[i][j];vis[i+1][j-2]=true;
	            q.push(make_pair(i+1, j-2));
	        }
	        if(valid(i-1,j+2,n))
	        {
	            b[i-1][j+2]=1+b[i][j];vis[i-1][j+2]=true;
	            q.push(make_pair(i-1, j+2));
	        }
	        if(valid(i-1,j-2,n))
	        {
	           // cout<<i-1<< " "<<j-2<<"\n";
	            b[i-1][j-2]=1+b[i][j];
	            //cout<<b[i-1][j-2]<<"\n";
	            vis[i-1][j-2]=true;
	            q.push(make_pair(i-1, j-2));
	        }
	        
	    }
	    return b[t[0]][t[1]];
	    
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends

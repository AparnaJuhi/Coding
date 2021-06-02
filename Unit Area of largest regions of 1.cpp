#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
 int dfs(vector<vector<int>>& grid, int n, int m)
    {
        if(n>=0 && n<grid.size() && m>=0 && m<grid[0].size() && grid[n][m]==1)
        {
            //mark it as visited
            grid[n][m]=0;
            return(1+dfs(grid,n+1,m) + dfs(grid,n-1,m) + dfs(grid,n,m+1)+ dfs(grid,n,m-1) + dfs(grid,n-1,m-1) + dfs(grid,n+1,m-1) + dfs(grid,n+1,m+1) + dfs(grid,n-1,m+1) );
        }
        return 0;
    }
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        
        //solving by dfs
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //if there is unvisited land
                if(grid[i][j]==1)
                {
                    maxi=max(maxi, dfs(grid, i, j));
                }
            }
        }
        return maxi;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends

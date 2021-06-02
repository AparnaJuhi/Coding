#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    void dfs(vector<vector<char>>& grid, int n, int m)
    {
        if(n>=0 && n<grid.size() && m>=0 && m<grid[0].size() && grid[n][m]=='1')
        {
            //mark it as visited
            grid[n][m]='0';
            dfs(grid,n+1,m);
            dfs(grid,n-1,m);
            dfs(grid,n,m+1);
            dfs(grid,n,m-1);
            dfs(grid,n-1,m-1);
            dfs(grid,n-1,m+1);
            dfs(grid,n+1,m-1);
            dfs(grid,n+1,m+1);
        }
        return;
    }
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        //by dfs
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //if there is unvisited land
                if(grid[i][j]=='1')
                {
                   count++;
                   dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends

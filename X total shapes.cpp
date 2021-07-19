#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
   
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        if(r>=0 && r<grid.size()&& c>=0 && c<grid[0].size() && grid[r][c]=='X')
        {
            grid[r][c]='0';
            dfs(grid, r+1, c);
            dfs(grid,r-1, c);
            dfs(grid, r, c+1);
            dfs(grid,r, c-1);
        }
        
    }
    int xShape(vector<vector<char>>& grid) 
    {
        int count=0;
        
       
        for(int i=0;i<grid.size();i++)
        {
             for(int j=0;j<grid[0].size();j++)
             {
                 if(grid[i][j]=='X')
                 {
                     dfs(grid, i, j);
                     count++;
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
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends

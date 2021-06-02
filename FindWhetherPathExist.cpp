#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    
    void dfs(vector<vector<int>>& grid, int n, int m)
    {
    
        //if position valid and there's no wall
        if(n>=0 && n<grid.size() && m>=0 && m<grid[0].size() && (grid[n][m]!=0 ))
        {
            //mark it as visited
                
            grid[n][m]=0;
            dfs(grid,n+1,m);
            dfs(grid,n-1,m);
            dfs(grid,n,m+1);
            dfs(grid,n,m-1);
            
        }
        return;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //first of all we will make a adjacency list as per the question
        
        int V=grid.size();
        vector<int>adj[V];
        
        int destinationx, destinationy,sourcex, sourcey;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
            if(grid[i][j]==1)
                {
                    sourcex=i;
                    sourcey=j;
                }
                else if(grid[i][j]==2)
                {destinationx=i;destinationy=j;}
            }
        }
        
        
        
        dfs(grid,sourcex, sourcey);
        if(grid[destinationx][destinationy]==0)
        return true;
        return false;
        
        //if the 
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends

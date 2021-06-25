#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
 void fun(vector<vector<int>>& image,int oldcolor, int sr, int sc, int newColor)
 {
     if(sr>=image.size() ||sr<0 || sc>=image[0].size() || sc<0)
        return;
        if(image[sr][sc]==newColor || image[sr][sc]!=oldcolor)
        return;
        if(image[sr][sc]==oldcolor)
        {
        image[sr][sc]=newColor;
        fun(image,oldcolor, sr+1, sc, newColor);
        fun(image,oldcolor, sr, sc+1, newColor);
        fun(image,oldcolor, sr-1, sc, newColor);
        fun(image,oldcolor, sr, sc-1, newColor);
        }
        return;
 }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int oldcolor=image[sr][sc];
        
        fun(image, oldcolor, sr, sc, newColor);
        
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends

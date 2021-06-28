
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    void rotate(vector<vector<int> >& mat) {
        int n=mat.size();
        for(int i=0;i<(n/2);i++)
        {
            int j=(n-1)-i;
            swap(mat[i],mat[j]);
        }
         for(int i=0;i<n;i++)
        {
            reverse(mat[i].begin(),mat[i].end());
            
        }
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.rotate(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends

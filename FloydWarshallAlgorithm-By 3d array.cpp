//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&m){
	    int n=m.size();
	    long long int a[n+1][n][n];
	   
	    
	    //where there is -1, convert to int max
	     for(int i=0;i<n;i++)
	       {
	             for(int j=0;j<n;j++)
	            {if(m[i][j]==-1)
	            {
	                m[i][j]=INT_MAX;
	            }
	            }
	       }
	       
	         for(int i=0;i<n;i++)
	       {
	             for(int j=0;j<n;j++)
	             {
	                 a[0][i][j]=m[i][j];
	             }
	   }
	    for(int k=0;k<n;k++)
	   {
	       for(int i=0;i<n;i++)
	       {
	             for(int j=0;j<n;j++)
	            {
	                if(i==k || j==k || i==j)
	                {
	                    a[k+1][i][j]=a[k][i][j];
	                }
	                else
	                {
	                
	                a[k+1][i][j]=min(a[k][i][j],a[k][i][k]+a[k][k][j]);
	                }
	            }
	           
	       }
	   }
	   
	   
	    for(int i=0;i<n;i++)
	       {
	             for(int j=0;j<n;j++)
	             {
	                 if(a[n][i][j]==INT_MAX)
	                 {
	                     m[i][j]=-1;
	                 }
	                 else
	                 m[i][j]=a[n][i][j];
	             }
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
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends

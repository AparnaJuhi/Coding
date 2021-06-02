#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   void dfs(vector<vector<int>>&a, int s, bool visited[])
   {
       visited[s]=true;
       for(int j=0;j<a[s].size();j++)
       {
           if(a[s][j]==1 && visited[j]==false)
           {
               dfs(a,j,visited);
           }
       }
   }
    int numProvinces(vector<vector<int>> a, int n) {
        //dfs
        
        
        int count=0;
        bool visited[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
        }
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false){
            count++;
            dfs(a,i,visited);
            }
            
        }
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends

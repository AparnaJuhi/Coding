// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

 bool safe(vector<vector<int>> board,int row,int col)
    {
        int i, j;
  int N=board.size();
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i]==1)
            return false;
  
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]==1)
            return false;
  
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j]==1)
            return false;
  
    return true;
        
    }
    
    
    bool check(vector<vector<int>>board, int col, int N,     vector<vector<int>>&res)
{
    /* base case: If all queens are placed
      then return true */
    if (col >= N)
    {
        vector<int>ans;
        for(int a=0;a<N;a++)
        {
            string p;
            for(int b=0;b<N;b++)
            {
                if(board[a][b]!=0)
                ans.push_back(b+1);
            }
           
            
        }
        res.push_back(ans);
    }
        
        
  
    /*try placing
       this queen in all rows one by one */
    for (int i = 0; i < N; i++) {
        
        if (safe(board, i, col)) {
            
            board[i][col] =1;
  
            /* recur to place rest of the queens */
            if (check(board, col + 1,N,res))
                return true;
  
            /* If placing queen in board[i][col]
               doesn't lead to a solution, then
               remove queen from board[i][col] */
            board[i][col] =0; // BACKTRACK
        }
    }
         return false;
    }
    vector<vector<int>> nQueen(int n) {
         vector<vector<int>>board;
      vector<vector<int>>res;
        for(int i=0;i<n;i++)
        {
            vector<int>k;
            for(int j=0;j<n;j++)
                k.push_back(0);
            board.push_back(k);
            k.clear();
        }
        
        check(board,0,n,res);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends

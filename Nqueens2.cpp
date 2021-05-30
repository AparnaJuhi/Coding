class Solution {
public:
bool safe(  int row, int col, vector<vector<int> > board )
{
    int i, j;
    int N = board.size();
 
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
 
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}
    bool fun( vector<vector<int>>board, int &count, int &n, int i)
    {
        if(i==n)
        {
            count++;
            return false;
        }
        
        for(int j=0;j<n;j++)
        {
            if(safe(j,i,board))
            {
                board[j][i]=1;
                
                bool jj=fun(board,count,n,i+1);
                    if(jj==false)
                    {
                        board[j][i]=0; //backtrack
                    }
            }
        }
        return false;
    }
    
    
    int totalNQueens(int n) {
        //make a board
        vector<vector<int>>board;
        for(int i=0;i<n;i++)
        {
            vector<int>k;
            for(int j=0;j<n;j++)
            {
              k.push_back(0); 
            }
            board.push_back(k);
            k.clear();
        }
        int count=0;
        fun(board,count,n,0);
        return count;
        
    }
};

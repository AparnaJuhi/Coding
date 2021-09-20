class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int  count=0;//to count no of blocks filled
        int a=0;
        int b=0,row,col;
        int mat[9];
        for(int i=0;i<9;i++)
            mat[i]=2;
        for(int i=0;i<moves.size();i++)
        {
            count++;
            vector<int>v=moves[i];
            row=v[0];
            col=v[1];
            if(a==0)
            {
                mat[row*3+col]=0;
                a=1;
            }
            else
            {
                mat[row*3+col]=1;
                a=0;
            }
            
            
        }
        
        int win[9][3]={{0,1,2},{3,4,5},{6,7,8},{0,4,8},{2,4,6},{0,3,6},{1,4,7},{2,5,8}};
        for(int i=0;i<8;i++)
        {
            if(mat[win[i][0]]== mat[win[i][1]] && mat[win[i][0]]== mat[win[i][2]] && mat[win[i][1]]== mat[win[i][2]])
            {
                if(mat[win[i][0]]!=2){
                if(mat[win[i][0]]==0)
                    return "A";
                else
                    return "B";
            }}
        }
        if(count<9)
            return "Pending";
        else
            return "Draw";
        
    }
};

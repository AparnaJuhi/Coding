class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        set<int>col;
        for(int i=0;i<mat.size();i++)
        {
            int flag=0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==0)
                {
                    col.insert(j);
                    flag=1;
                }
            }
            if(flag==1)
            {
                 for(int j=0;j<mat[i].size();j++)
                     mat[i][j]=0;
            }
        }
        for(int j=0;j<mat[0].size();j++)
        {
             if(col.find(j)!=col.end())
             for(int i=0;i<mat.size();i++)
             {
                
                mat[i][j]=0;
             }
        }
        
        
    }
};

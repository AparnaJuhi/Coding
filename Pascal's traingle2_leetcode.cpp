class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>mat;
        for(int i=0;i<=rowIndex;i++)
        {vector<int>p;
        p.push_back(1);
        mat.push_back(p);}
        for(int i=1;i<=rowIndex;i++)
        {
            
            for(int j=1;j<i;j++)
            {
                mat[i].push_back(mat[i-1][j-1]+mat[i-1][j]);
            }
            mat[i].push_back(1);
        }
        return mat[rowIndex];
        
    }
};

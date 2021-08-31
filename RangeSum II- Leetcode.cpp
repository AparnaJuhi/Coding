class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minix=m;
        int miniy=n;
        for(int i=0;i<ops.size();i++)
        {
            minix=min(minix,ops[i][0]);
            miniy=min(miniy,ops[i][1]);
        }
        return minix*miniy;

        
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int prev=0;
        int curr=0;
        for(int i=0;i<gas.size();i++)
        {
            curr+=gas[i]-cost[i];
            if(curr<0)
            {
                start=i+1;
                prev=curr+prev;
                curr=0;
            }
        }
        if(prev+curr>=0)
            return start;
        return -1;
    }
};

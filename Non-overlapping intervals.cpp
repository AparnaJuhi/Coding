class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& i) {
        //count maximum number of non overlapping intervals
        
        vector<pair<int,int>>v;
        for(int j=0;j<i.size();j++)
        {
            int s=i[j][0];
            int e=i[j][1];
            v.push_back(make_pair(e,s));
        }
        sort(v.begin(),v.end());
        int count=1;
        int j=0;
        int new_end=v[0].first;
        for(int k=1;k<v.size();k++)
        {
            if(v[k].second>= new_end)
            {
                new_end=v[k].first;
                count++;
            }
        }
        return v.size()-count;
        
    }
};

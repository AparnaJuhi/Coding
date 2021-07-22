class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
         vector<pair<int,int>>v;
        for(int j=0;j<points.size();j++)
        {
            int s=points[j][0];
            int e=points[j][1];
            v.push_back(make_pair(s,e));
        }
        sort(v.begin(),v.end());
        int count=1;
        int start=v[0].first;
        int end=v[0].second;
        for(int i=1;i<points.size();i++)
        {
            if(v[i].first<=end)
            {
                end=min(v[i].second,end);
                continue;
            }
            else
            {
                count++;
                start=v[i].first;
                end=v[i].second;
            }
        }
        
        return count;
    }
};

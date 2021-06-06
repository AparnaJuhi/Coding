class Solution {
public:
    static bool comp(pair<int,int>a, pair<int,int>b)
    {
        return a.second<b.second;
    }
    int findLongestChain(vector<vector<int>>& p) {
        int n=p.size();
        int ans=1;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            int st=p[i][0];
            int en=p[i][1];
            v.push_back(make_pair(st,en));
        }
        sort(v.begin(),v.end(),comp);
        int end=v[0].second;
         for(int i=1;i<n;i++)
         {
             if(v[i].first>end)
             {
                 end=v[i].second;
                 ans++;
             }
         }
         return ans;
       //its like maximum number of meetings in a room
        //solving by greedy
        
    }
};

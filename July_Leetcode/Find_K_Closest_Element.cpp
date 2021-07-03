class Solution {
public:
    static bool comp(pair<int,int>a, pair<int,int>b)
    {
        if(a.first < b.first)
            return true;
        else if(a.first==b.first)
        {
            if(a.second<b.second)
                return true;
            return false;
        }
        return false;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //vector pair to store the diff and corresponding element
       vector<pair<int,int>>v;
        for(int i=0;i<arr.size();i++)
        {
            int y=abs(x-arr[i]);
            v.push_back(make_pair(y,arr[i]));
        }
        sort(v.begin(),v.end(),comp);
        vector<int>ans;
        for(int j=0;j<k;j++)
        {
            ans.push_back(v[j].second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

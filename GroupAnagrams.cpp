class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            string p=strs[i];
            sort(p.begin(),p.end());
           
                mp[p].push_back(strs[i]);
           
        }
         map<string,vector<string>>:: iterator it;
        vector<vector<string>> vec;
        for(it=mp.begin();it!=mp.end();++it)
        {
            vec.push_back(it->second);
        }
        return vec;
        
    }
};

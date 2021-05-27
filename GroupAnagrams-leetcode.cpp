class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         vector<vector<string>>ans;
        map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            string k=strs[i];
            sort(k.begin(),k.end());
            if(mp.find(k)==mp.end())
            {
                vector<string>t;
                t.push_back(strs[i]);
                mp[k]=t;
            }
            else
            {
                mp[k].push_back(strs[i]);
            }
        }
         map<string,vector<string>>:: iterator it;
        
        for(it=mp.begin();it!=mp.end();++it)
        {
            ans.push_back(it->second);
        }
        return ans;
        
    }
};

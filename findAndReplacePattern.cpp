class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(int i=0;i<words.size();i++)
        {
            map<char,char>mp;
            int j=0;map<char,char>mp1;
            for(j=0;j<words[i].size();j++)
            {
                if(mp.find(pattern[j])==mp.end())
                {
                    mp[pattern[j]]=words[i][j];
                }
                else
                {
                    if( mp[pattern[j]]!=words[i][j])
                          break;
                }
                if(mp1.find(words[i][j])==mp1.end())
                {
                    mp1[words[i][j]]=pattern[j];
                }
                else
                {
                    if( mp1[words[i][j]]!=pattern[j])
                          break;
                }
            }mp1.clear();mp.clear();
             if(j==words[i].size())
              ans.push_back(words[i]);
        }
                          return ans;
    }
};

#include<bits/stdc++.h>
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            string word1=words[i];
            set<char>s;
            for(int j=0;j<word1.size();j++)
            {
                s.insert(word1[j]);
            }
            for(int j=i+1;j<n;j++)
            {
                string word2=words[j];
                int flag=0;
                for(int k=0;k<word2.size();k++)
                {
                    if(s.find(word2[k])!=s.end())
                    {
                        flag=1;break;
                    }
                }
                
                if(flag==0)
                {
                    int z=word1.size()*word2.size();
                    if(ans<z)
                    ans=z;
                }
            }
        }
        return ans;
        
    }
};

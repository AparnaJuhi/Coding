class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        //store elements and their indices in a map
        map<char,int>mp;
        int maxi=0;
        int count=0;
        int n=s.size();
        //temp to track that whether the hash of the string is greater or the point from where we have started.
        //ex: abdedaf, here hash[a]=0 initially, and already our start is 3, so no need for any update
        int temp=-1;
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                mp[s[i]]=i;
                count++;
               
            }
            else
            {
                if(mp[s[i]]<temp)
                {
                    mp[s[i]]=i;
                    count++;
                }
                else
                {
                    temp=mp[s[i]];
                    count=(i-temp);
                    mp[s[i]]=i;
                }
            }
             maxi=max(maxi,count);
        }
        return maxi;
        
    }
};

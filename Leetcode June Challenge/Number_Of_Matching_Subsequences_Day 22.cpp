class Solution {
public:
    bool fun(string m, string n)
    {
        int a=m.size();
        int b=n.size();
        int k=0, count=0;
        for(int i=0;i<a;i++)
        {
            if(m[i]==n[k])
            {
                count++;k++;
            }
            
            if((b-k) > (a-i))
                return false;
            
            if(k==b)
            {
                return true;
            }
           
        
        }
        if(count==b)
            return true;
        
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        //finding subsequence
        int count=0;
        
        //map to store count of each words, so that we don'tneeed to check it
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++)
        {
            if(mp.find(words[i])==mp.end())
                mp[words[i]]=1;
            else
                mp[words[i]]+=1;
        }
        
        unordered_map<string,int>:: iterator it;
        for(it=mp.begin();it!=mp.end();++it)
        {
            if(it->first.size()>s.size())
                continue;
            else if(it->first.size()==s.size())
            {
                if(it->first==s)
                    count+=it->second;
                else
                    continue;
            }
            else{
            if(fun(s,it->first))
                count+=it->second;
            }
        }
        return count;
            
    }
};

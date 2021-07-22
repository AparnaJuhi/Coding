class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            string p="";
            for(int j=i;j<s.size();j++)
            {
                p+=s[j];
                string t=p;
                reverse(t.begin(),t.end());
                if(t==p)
                    count++;
            }
        }
        return count;
    }
};

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=shifts.size();
        int pref[n+1];
        pref[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            shifts[i]=shifts[i]%26;
            pref[i]=(pref[i+1]+shifts[i])%26;
        }
        
        for(int i=0;i<s.size();i++)
        {
            int num=(int(s[i]-97)+pref[i])%26;
            char p=num+97;
            s[i]=p;
        }
        return s;
        
    }
};

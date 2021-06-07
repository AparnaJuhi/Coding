class Solution {
public:
    bool isHappy(int n) {
        if(n==1)
            return true;
        set<int>sett;
        while(1)
        {
            string s=to_string(n);
            if(sett.find(n)!=sett.end())
                return false;
            
            sett.insert(n);
            int sum=0;
            for(int i=0;i<s.size();i++)
            {
                sum=sum+pow((((int)s[i]) -48),2);
                
            }
            n=sum;
            if(n==1)
                return true;
            
            
        }
        return true;
    }
};

class Solution {
public:
    bool fun(string s, int i, int n, int &count,string p)
    {
        if(i>n)
        {
            
            count++;
            return false;
        }
        if(s[i]=='0')
               return false;
           
            fun(s,i+1,n,count,p);
           
            if(i+1 <= n )
            {
                string pp="";
                pp+=s[i];
                pp+=s[i+1];
               
                if(pp>="10" && pp<="26")
                {
                    fun(s, i+2 , n, count,p+pp);
                }
            }
        
        return false;
    }
    int numDecodings(string s) {
        
        //backtracking
        if(s[0]=='0')
            return 0;
        if(s.size()==1)
            return 1;
        string ans="";
        int count=0;
        string p="";
        fun(s,0,s.size()-1,count,p);
        return count;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int count=0;
        
        //fiding shortest string
        string start=strs[0];
        for(int i=1;i<n;i++)
        {
            if(strs[i].size()<start.size())
            {
                start=strs[i];
            }
        }
       
       int flag=0;
        string ans="";
        for(int i=0;i<start.size();i++)
        {
           // int flag=0;
            for(int j=0;j<n;j++)
            {
                if(strs[j][i]!=start[i])
                {
                    flag=1;break;
                }
                    
            }
            if(flag==1)
                return ans;
            else
                ans+=start[i];
        }
        return ans;
        
    }
};

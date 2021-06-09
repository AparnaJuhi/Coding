class Solution {
public:
    bool fun(vector<char>&v , int &n,int &count, string &s, int idx)
    {
        if(s.size()>=n)
        {
            count=((count%1000000007)+1)%1000000007;
            return false;
        }
        for(int i=idx;i<5;i++)
        {
            //to reduce unncessary func call, as ther is only one possibility that all characters after u should              //be u
            if(v[i]=='u')
            {count+=1;continue;}
            s+=v[i];
            bool k= fun(v, n, count, s, i);
            if(k==false)
            s = s.substr(0, s.size()-1);
        }
        return false;
    }
    int countVowelStrings(int n) {
        
        //backtracking
        vector<char>v;
        v.push_back('a');v.push_back('e');
        v.push_back('i');
        v.push_back('o');
        v.push_back('u');   
        int count=0;
        string s="";
        fun(v,  n, count, s, 0);
        return count;
        
    }
};

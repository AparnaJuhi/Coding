class Solution {
public:
    void backtrack(string str, int open, int close, int n,  vector<string>&ans)
    {
        if(str.size() == 2*n)
        {
            ans.push_back(str);
        }
        if(open < n)
        {
            backtrack(str+'(' , open+1, close, n, ans);
        }
        if(close<open)
            backtrack(str+')' , open, close+1, n, ans);
    }
    vector<string> generateParenthesis(int n) {
        
        string res="";
        vector<string>ans;
        backtrack("", 0, 0, n, ans);
        return ans;
        
    }
};

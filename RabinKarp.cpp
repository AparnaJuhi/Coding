#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int txtcount=0;
            int patcount=0;
            int d=5;
            int q=101;
            for(int i=0;i<pat.size();i++)
            {
                txtcount=(txtcount*d+txt[i])%q;
                patcount=(patcount*d+pat[i])%q;
            }
            int dn1=1;
            for(int i=1;i<pat.size();i++)
            {
               dn1=(dn1*d)%q;
            }
            vector<int>v;
            for(int i=0;i<=(txt.size()-pat.size());i++)
            {
                
                if(txtcount==patcount)
                {
                    int j;
                    for(j=0;j<pat.size();j++)
                    {
                        if(txt[i+j]!=pat[j])
                        break;
                        
                    }
                    if(j==pat.size())
                    v.push_back(i+1);
                }
                if(i<(txt.size()-pat.size()))
                {
                    txtcount=(d*(txtcount-txt[i]*dn1) + txt[i+pat.size()])%q;
                    if(txtcount<0)
                    txtcount+=q;
                }
            }
            if(v.empty())
            {
                v.push_back(-1);
                return v;
            }
            return v;
        }
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


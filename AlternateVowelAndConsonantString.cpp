#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    string rearrange (string S, int N)
    {
        vector<char>v,c;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='a' || S[i]=='e'   || S[i]=='i'   || S[i]=='o'   || S[i]=='u')
            v.push_back(S[i]);
            else
            c.push_back(S[i]);
        }
        //cout<<v.size()<<"  "<<c.size()<<"\n";
        int p=(v.size()-c.size());
        if(p<0)
        p=-1*p;
        //cout<<p<<"\n";
        if(p>=2)
        return "-1";
        sort(v.begin(),v.end());
        sort(c.begin(),c.end());
        string ans;
        if(v.size()==c.size())
        {
              int k=0,j=0;
            int flag=0;
            if(v[0]<c[0])
            {
                ans=v[0];
                flag=1;
                k++;
            }
            else
            {
                ans=c[0];
                j++;
            }
          
            if(flag==1)
            {
                for(int i=1;i<S.size();i++)
                {
                    if(i%2==0)
                    {
                        ans+=v[k];k++;
                    }
                    else
                    {
                        ans+=c[j];j++;
                    }
                }
            }
            
            else
            {
                for(int i=1;i<S.size();i++)
                {
                    if(i%2!=0)
                    {
                        ans+=v[k];k++;
                    }
                    else
                    {
                        ans+=c[j];j++;
                    }
                }
            }
        }
        
        else if(v.size()<c.size())
        {
              int k=0,j=0;
             ans=c[0];
                j++;
                for(int i=1;i<S.size();i++)
                {
                    if(i%2!=0)
                    {
                        ans+=v[k];k++;
                    }
                    else
                    {
                        ans+=c[j];j++;
                    }
                }
        }
        
        else
        {
            
            int k=0,j=0;
             ans=v[0];
                k++;
                for(int i=1;i<S.size();i++)
                {
                    if(i%2==0)
                    {
                        ans+=v[k];k++;
                    }
                    else
                    {
                        ans+=c[j];j++;
                    }
                }
            
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}

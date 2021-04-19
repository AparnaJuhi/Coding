#include<bits/stdc++.h>
using namespace std;
bool palindrome(string s)
{
    int n=s.size();
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=s[n-i-1])
        return false;
    }
    return true;
}
int main()
{
	string s;
	cin>>s;
	string ans="";
	int count=0;
	//string tt;
	int t=s.size()-1;
	while(palindrome(s)==false)
	{
	    
	    ans+=s[t];
	    t--;
	    count++;
	    if(palindrome(ans+s))
	    break;
	    
	}
	cout<<count;
	return 0;
}


//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    bool fun( vector<string>&ans, map<int,string>mp, string s, int a[], int idx, int n)
    {
        if(s.size()==n)
        {
            ans.push_back(s);
            return false; 
        }
        
        string p=mp[a[idx]];
        for(int i=0;i<p.size();i++)
        {
            s+=p[i];
            if(fun(ans, mp, s, a, idx+1 , n)==false)
            {
                s = s.substr(0, s.size()-1);
            }
        }
        return false;
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        string s="";
        vector<string>ans;
        map<int, string>mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        fun(ans, mp , s, a, 0, N);
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends

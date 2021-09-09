#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool sub(string A, string B)
  {
     if (A.find(B) != std::string::npos)
     return true;
     return false;
  }
    int minRepeats(string A, string B) {
        string p=A;
        int count=1;
        int k;
        int num=ceil(B.size()/A.size());
        k=num;
        while(num>1)
        {
            A+=p;
            num--;
        }
        if(sub(A,B))
           {
               return k;
           }
       A+=p;
       if(sub(A,B))
           {
               return k+1;
           }
       return -1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends

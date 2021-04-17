// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int rank(string S){
        int n=S.size();
        string curr="";
         long long int fact[n];
            fact[0]=1;
            fact[1]=1;
            for(int i=2;i<n;i++)
            {
                fact[i]=((fact[i-1]%1000003)*(i%1000003))%1000003;
            }
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            char t=S[i];
            int count=0;
            //count no of elements on LHS smaller than the current character
            for(int j=i+1;j<n;j++)
            {
                if(S[j]<S[i])
                count++;
                else if(S[i]==S[j])
                return 0;
            }
            
           
            sum+=((fact[n-i-1]%1000003)*(count%1000003))%1000003;
        }
        return (sum+1)%1000003;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.rank(S)<<endl;
    }
    return 0;
}  // } Driver Code Ends

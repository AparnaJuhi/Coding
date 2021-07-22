//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string s){
        //here we know that alphabets are in between 0 and 26
        int arr[26];
        for(int i=0;i<26;i++)
        arr[i]=0;
        
        //count elements
        for(int i=0;i<s.size();i++)
        {
            arr[int(s[i])-97]+=1;
           
        }
        //making arr a prefix sum
       
        for(int i=1;i<26;i++)
        {arr[i]=arr[i-1]+arr[i];}
        
       char brr[s.size()];
        for(int i=0; i<s.size();i++)
        {
            brr[arr[int(s[i])-97]-1]=s[i];
          // cout<<arr[int(s[i])-97]<<"  ";
            arr[int(s[i])-97]-=1;
        }
        
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            ans+=brr[i];
        }
       
        return ans;
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}
  // } Driver Code Ends

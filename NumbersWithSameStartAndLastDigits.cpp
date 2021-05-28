#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int numbersInRange(int L, int R){
        // code here
        
        //count such numbers from 1 to l-1
        
        if(L>R)
        return 0;
        int count=0;
        int temp=L-1;
        count=(temp/10);
        string m=to_string(temp);
        int siz=m.size();
        int firstchar=temp/pow(10,siz-1);
        int lastchar=temp%10;
        if(firstchar>lastchar)
        {
            count--;
        }
       
        if(temp>9)
        {
            count+=9;
        }
        else
        count+=temp;
        
        
        
        int count2=0;
        temp=R;
        count2=(temp/10);
        m=to_string(temp);
        siz=m.size();
        firstchar=temp/pow(10,siz-1);
        lastchar=temp%10;
        if(firstchar>lastchar)
        {
            count2--;
        }
        
        if(temp>9)
        {
            count2+=9;
        }
        else
        count2+=temp;
        
        return count2-count;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int L, R;
        cin >> L >> R;
        Solution ob;
        cout << ob.numbersInRange(L, R) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends

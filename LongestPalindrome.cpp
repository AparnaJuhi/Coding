class Solution {
public:
    int longestPalindrome(string s) {
       
    int arr[256];
     for(int i=0;i<256;i++)
     {
         arr[i]=0;
     }
     for(int i=0;i<s.size();i++)
     {
         
             arr[int(s[i])]+=1;
        
    }
    int count=0;
    int flag=0;
        
    for(int i=0;i<s.size();i++)
     {
         
         int q=arr[int(s[i])]/2;
                    count+=(q*2);
                    arr[int(s[i])]-=(2*q);     
          
        if(flag==0 && arr[int(s[i])]==1)
        {
            count+=1;
            flag=1;
        }
    }
        return count;
    }
        
        
};

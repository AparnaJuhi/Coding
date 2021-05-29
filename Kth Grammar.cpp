class Solution {
public:
    int kthGrammar(int n, int k) {
        if(k==1 && n==1)
            return 0;
        int mid=pow(2,n-1)/2;
        if(k<=mid)
        {
            //first half is same as n-1.
           return kthGrammar(n-1,k);
        }
        else
        {
            //second half is not of n-1
           return !kthGrammar(n-1,k-mid);
        }
        
    }
};

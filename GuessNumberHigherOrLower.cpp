/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int bs(long long int l, long long int r)
    {
        while(l<=r)
        {
            long long int mid=(l+r)/2;
            int res= guess(mid);
            if(res==0)
                return mid;
            else if(res==1)
            {
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return -1;
    }
    int guessNumber(int n) {
    
        return bs(1,n);
        
    }
};

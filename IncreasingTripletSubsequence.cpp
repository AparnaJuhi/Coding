class Solution {
public:

    int binarySearch(int a[], int l, int r, int val)
    {
        while(l<r)
        {
            int mid=(l+r)/2;
            if(a[mid]>=val)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return r;
    }
    
    bool increasingTriplet(vector<int>& arr) {
        
        //make one more array named as tail
        
        int n=arr.size();
        int tail[n];
        tail[0]=arr[0];
        int len=1;
        //to store length
        for(int i=1;i<n;i++)
        {
            if(arr[i]>tail[len-1])
            {
                tail[len]=arr[i];
                len++;
            }
            else
            {
                int idx=binarySearch(tail,0,len,arr[i]);
                tail[idx]=arr[i];
            }
        }
        if(len>=3)
            return true;
        else
            return false;
        
    }

};

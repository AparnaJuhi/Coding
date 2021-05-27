class Solution {
public:
    int search(vector<int>& a, int target) {
        
        //it is guarantted that one half one will be sorted
        
        int ans=-1;
        int l=0;
        int r=a.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(a[mid]==target)
                return mid;
            if(a[mid]>=a[l])
            {
                //left half sorted
                if(target<a[mid] && target>=a[l])
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            else
            {
                //right half sorted
                 if(target>a[mid] && target<=a[r])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        }
        return ans;
    }
};

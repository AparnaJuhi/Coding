class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size();
        int n2=nums2.size();
         double two=2.00;
        //time complexity log(m+n)
        if(n1<=n2)
        {
            //consider nums1
            int start=0;
            int end=n1;
            int max1=INT_MIN,max2=INT_MIN;
            int min1=INT_MAX, min2=INT_MAX;
            while(start<=end)
            {
                int i1=(start+end)/2; //mid in nums1
                int i2=((n1+n2+1)/2)-i1;
                if(i1>0)
                {
                    max1=nums1[i1-1];
                }
                else
                {
                    max1=INT_MIN;
                }
                if(i2>0)
                {
                    max2=nums2[i2-1];
                }
                else
                {
                    max2=INT_MIN;
                }
                if(i1<n1)
                {
                    min1=nums1[i1];
                }
                else
                    min1=INT_MAX;
                if(i2<n2)
                    min2=nums2[i2];
                else
                    min2=INT_MAX;
                if(min2>=max1 && min1>=max2)
                {
                    //ideal condition
                    if((n1+n2)%2!=0)
                        return max(max1,max2);
                    else
                        return ((double)((max(max1,max2)+min(min1,min2))/two));
                }
                else if(max1>min2)
                {
                    end=i1-1;
                }
                else
                {
                    start=i1+1;
                }
                
            }
            
        }
        else
        {
            int start=0;
            int end=n2;
            int max1=INT_MIN,max2=INT_MIN;
            int min1=INT_MAX, min2=INT_MAX;
            while(start<=end)
            {
                int i1=(start+end)/2; //mid in nums1
                int i2=((n1+n2+1)/2)-i1;
                if(i1!=0)
                {
                    max1=nums2[i1-1];
                }
                else
                {
                    max1=INT_MIN;
                }
                if(i2!=0)
                {
                    max2=nums1[i2-1];
                }
                else
                {
                    max2=INT_MIN;
                }
                if(i1<n2)
                {
                    min1=nums2[i1];
                }
                else
                    min1=INT_MAX;
                
                if(i2<n1)
                    min2=nums1[i2];
                else
                    min2=INT_MAX;
                if(min2>=max1 && min1>=max2)
                {
                   
                    //ideal condition
                    if((n1+n2)%2!=0)
                        return (double)max(max1,max2);
                    else
                        return ((double)(max(max1,max2)+min(min1,min2))/two);
                }
                else if(min1<max2)
                {
                    start= i1+1;
                }
                else
                {
                    end=i1-1;
                }
                
            }
        }
        return 0;
            
    }
};

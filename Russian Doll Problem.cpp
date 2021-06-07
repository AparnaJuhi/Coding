class Solution {
public:
    static bool comp(vector<int>a,vector<int>b)
    {
        if(a[0] < b[0])
            return true;
        else if(a[0]==b[0])
        {
            if(a[1] < b[1])
                return true;
            else
                return false;
        }
        return false;
    }
    int bs(int tail[], int l , int r, int key)
    {
        while(l<r)
        {
            int mid=(l+r)/2;
            if(tail[mid]>key)
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
    int maxEnvelopes(vector<vector<int>>& es) {
        //sort acc to width of dolls
        //you can sort acc to any- width or height
        sort(es.begin(),es.end(),comp);
        int n=es.size();

        int len=0;
     
        int lis[n];
        memset(lis,0,n);
        for(int i=0;i<n;i++)
        {   int maxi=0;
            for(int j=0;j<i;j++)
            {
                if(es[j][0] < es[i][0] && es[j][1]< es[i][1])
                {
                    if(lis[j]>maxi)
                    {
                        maxi=lis[j];
                    }
                }
            }
            lis[i]=maxi+1;
            len=max(lis[i],len);
        }
        return len;
    }
};

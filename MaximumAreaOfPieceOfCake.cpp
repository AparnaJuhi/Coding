class Solution {
public:
    int maxArea(int x, int y, vector<int>& h, vector<int>& v) {
        h.push_back(0);
        h.push_back(x);
        v.push_back(0);
        v.push_back(y);
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        int mod=1000000007;
        
        long long int  maxi=0;
        long long int ans;int i;
        
            for(i=1;i<h.size();i++)
            {
                if((h[i]-h[i-1]) >maxi)
                 maxi=(h[i]-h[i-1]);
            }
            
        
         long long int  maxii=0;
        for(i=1;i<v.size();i++)
            {
                if((v[i]-v[i-1]) >maxii)
                 maxii=(v[i]-v[i-1]);
            }
            
        
        ans=((maxi*maxii)%mod);
        return ans;
    }
};

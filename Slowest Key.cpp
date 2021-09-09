class Solution {
public:
    char slowestKey(vector<int>&v, string keys) {
        int n=v.size();
        long long arr[n];
        arr[0]=v[0]; 
        char ans=keys[0];
        int maxi=arr[0];
       
        for(int i=1;i<n;i++)
        {
            arr[i]=v[i]-v[i-1];
            if(arr[i] > maxi)
            {maxi=arr[i];ans=keys[i];}
            else if(arr[i]==maxi && keys[i]>ans)
            {
                ans=keys[i];
            }
        }
        return ans;
        
        
    }
};

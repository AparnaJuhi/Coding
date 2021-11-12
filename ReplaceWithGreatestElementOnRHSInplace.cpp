class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int>p(arr.size());
        int n=arr.size();
        int val=arr[n-1];
        arr[n-1]=-1;
        for(int k=n-2;k>=0;k--)
        {
            int t=max(arr[k], val);
            arr[k]=max(arr[k+1],val);
            val=t;
        }
        return arr;
        
    }
};

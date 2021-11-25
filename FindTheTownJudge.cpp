class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int arr[n+1];
        int brr[n+1];
        for(int i=0;i<=n;i++)
        {
            arr[i]=0;brr[i]=0;
        }
        
        for(int i=0;i<trust.size();i++)
        {
            arr[trust[i][1]]+=1; // to the node
            brr[trust[i][0]]+=1; //from the node
        }
        for(int i=1;i<=n;i++)
        {
            cout<<arr[i]<< "  "<<brr[i]<<"\n";
            if(arr[i]==n-1 && brr[i]==0)
                return i;
        }
        return -1;
    }
};

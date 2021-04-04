#include <bits/stdc++.h> 
using namespace std; 
class Solution
{   
public:     
    void rotateby90(vector<vector<int> >&a, int n) 
    { 
        for(int i=0;i<n;i++)
        {
            for(int j=(i+1);j<n;j++)
            {
                swap(a[i][j],a[j][i]);
            }
        }
         for(int i=0;i<n;i++)
        {
            int k=n-1;
            int mid=n/2;
            for(int j=0;j<(mid);j++)
            {
                swap(a[j][i],a[k][i]);
                k--;
            }
        }
    } 
};
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
